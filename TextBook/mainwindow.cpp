#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include "Model/slide.h"
#include "Model/lecture.h"
#include "Import/xmlimporter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    initModel();
    currentContent = model;
    ui->setupUi(this);
    enableControls();
    updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    if (model != Q_NULLPTR)
        delete model;
}

void MainWindow::on_butInfo_clicked()
{
    QMessageBox::about(this, "О Программе",
                       "Электронный учебник\n\n"
                       "Разработала:\n"
                       "студентка группы 5303 Табунникова Н.Р.\n"
                       "\nЛЭТИ, Санкт-Петербург, 2018 год.\n");
}

void MainWindow::on_butForward_clicked()
{
    if (currentContent->viewType() == ContentViewType::SelectorView) {
        currentContent = reinterpret_cast<ContentPart*>(currentContent->selectedItem());
        if (currentContent->selectedItem() == Q_NULLPTR)
            currentContent->forward();
    }
    else
        currentContent->forward();
    enableControls();
    updateView();
}

void MainWindow::on_butBackward_clicked()
{
    currentContent->backward();
    enableControls();
    updateView();
}

void MainWindow::on_butLevelUp_clicked()
{
    currentContent = currentContent->parent();
    enableControls();
    updateView();
}

void MainWindow::on_butQuiz_clicked()
{
    // TODO
}

void MainWindow::initModel()
{
    model = new ContentModel();
    model->setName("Список учебных курсов");

    QDir dir(dataFolder(), "*.xml");
    XmlContentImporter importer;
    foreach(QString entry, dir.entryList())
        importer.importCourse(model, dir.absoluteFilePath(entry));

    model->forward();
}

void MainWindow::enableControls()
{
    ui->butQuiz->setEnabled(false); // TODO
    ui->butLevelUp->setEnabled(currentContent->canLevelUp());
    ui->butBackward->setEnabled(currentContent->canBackward());
    ui->butForward->setEnabled(currentContent->canForward());
}

void MainWindow::updateView()
{
    if (currentContent->viewType() == ContentViewType::SelectorView) {
        if (ui->stackedWidget->currentIndex() != 0)
            ui->stackedWidget->setCurrentIndex(0);
        ui->selectorCaption->setText(currentContent->name());
        ui->selectorList->clear();
        foreach (ContentItem *item, currentContent->items()) {
            ui->selectorList->addItem(item->name());
        }
        ui->selectorList->setCurrentRow(currentContent->selectedIndex());
    }
    else if (currentContent->viewType() == ContentViewType::SlideView) {
        if (ui->stackedWidget->currentIndex() != 1)
            ui->stackedWidget->setCurrentIndex(1);
        ContentItem *item = currentContent->selectedItem();
        if (item != Q_NULLPTR) {
            ui->slideCaption->setText(item->name());
            ui->slideTextArea->setText(item->description());
        }
        else {
            ui->slideCaption->setText("");
            ui->slideTextArea->setText("");
        }
        Slide *slide = dynamic_cast<Slide*>(item);
        if (slide != Q_NULLPTR)
            loadSlideImage(slide->imagePath());
        else
            loadSlideImage("");
    }
}

QString MainWindow::dataFolder() const
{
    return "D:/Git/gui-1h2018-19/TextBook/Data";
}

void MainWindow::loadSlideImage(QString imagePath)
{
    ui->slideImage->setScene(Q_NULLPTR);
    scene->clear();
    if (!imagePath.isEmpty()) {
        QDir dir(dataFolder());
        QPixmap image(dir.absoluteFilePath(imagePath));
        QRect imageRect = image.rect();
        QGraphicsPixmapItem *pixmapItem = scene->addPixmap(image);
        pixmapItem->setTransformationMode(Qt::SmoothTransformation);
        scene->setSceneRect(imageRect);
        ui->slideImage->setScene(scene);
        QRect frameRect = ui->slideImage->rect();
        if (imageRect.width() > frameRect.width() || imageRect.height() > frameRect.height())
            ui->slideImage->fitInView(imageRect, Qt::KeepAspectRatio);
    }
}

void MainWindow::on_selectorList_currentRowChanged(int currentRow)
{
    currentContent->setSelectedIndex(currentRow);
    ContentItem *item = currentContent->selectedItem();
    if (item != Q_NULLPTR)
        ui->selectorTextArea->setText(item->description());
    else
        ui->selectorTextArea->setText("");
}

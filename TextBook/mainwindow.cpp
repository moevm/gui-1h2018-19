#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Model/slide.h"
#include "Model/lecture.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initModel();
    currentContent = model;
    ui->setupUi(this);
    enableControls();
    updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
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

    ContentPart *course = new ContentPart(model);
    course->setName("Учебный курс 1");
    course->setDescription("Описание курса 1");

    Lecture *lecture = new Lecture(course);
    lecture->setName("Лекция 1.1");
    lecture->setDescription("Описание лекции 1.1");

    Slide *slide = new Slide(lecture);
    slide->setName("Слайд 1.1.1");
    slide->setDescription("Текст слайда 1.1.1");

    slide = new Slide(lecture);
    slide->setName("Слайд 1.1.2");
    slide->setDescription("Текст слайда 1.1.2");

    lecture = new Lecture(course);
    lecture->setName("Лекция 1.2");
    lecture->setDescription("Описание лекции 1.2");

    slide = new Slide(lecture);
    slide->setName("Слайд 1.2.1");
    slide->setDescription("Текст слайда 1.2.1");

    slide = new Slide(lecture);
    slide->setName("Слайд 1.2.2");
    slide->setDescription("Текст слайда 1.2.2");

    course = new ContentPart(model);
    course->setName("Учебный курс 2");
    course->setDescription("Описание курса 2");

    lecture = new Lecture(course);
    lecture->setName("Лекция 2.1");
    lecture->setDescription("Описание лекции 2.1");

    slide = new Slide(lecture);
    slide->setName("Слайд 2.1.1");
    slide->setDescription("Текст слайда 2.1.1");

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

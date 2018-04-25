#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QDialogButtonBox>
#include "Model/slide.h"
#include "Model/lecture.h"
#include "Import/xmlimporter.h"
#include "optionsdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_dataFolder = "F:/Git/Sandbox/TextBook/Data";
    scene = new QGraphicsScene();
    initModel();
    currentContent = model;
    ui->setupUi(this);
    initNavigator();
    enableControls();
    updateView();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    if (model != Q_NULLPTR) {
        model->saveProgress();
        delete model;
    }
}

void MainWindow::on_butInfo_clicked()
{
    OptionsDialog *dialog = new OptionsDialog(this);
    dialog->setDataFolder(dataFolder());
    int result = dialog->exec();
    if (result == QDialog::Accepted)
        setDataFolder(dialog->dataFolder());
}

void MainWindow::on_butForward_clicked()
{
    if (currentContent->viewType() == ContentViewType::SelectorView) {
        currentContent = reinterpret_cast<ContentPart*>(currentContent->selectedItem());
        if (currentContent->selectedItem() == Q_NULLPTR)
            currentContent->forward();
    }
    else if (currentContent->viewType() == ContentViewType::QuizView) {
        Question* question = dynamic_cast<Question*>(currentContent->selectedItem());
        if (question != Q_NULLPTR) {
            int selectedAnswerIndex = ui->questionList->currentRow();
            if (selectedAnswerIndex < 0) {
                QMessageBox::warning(this, "Контрольные вопросы", "Выберите один из ответов на вопрос!");
                return;
            }
            if (selectedAnswerIndex != question->correctAnswerIndex()) {
                QMessageBox::warning(this, "Контрольные вопросы", "Вы ответили неправильно!");
                question->setProgress(0.2f);
            }
            else {
                QMessageBox::warning(this, "Контрольные вопросы", "Вы дали правильный ответ!");
                question->setProgress(1.0f);
            }
            if (currentContent->selectedIndex() == currentContent->items().count() - 1)
                currentContent = currentContent->parent();
            else
                currentContent->forward();
        }
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
    Lecture *lecture = dynamic_cast<Lecture*>(currentContent);
    if (lecture != Q_NULLPTR) {
        if (lecture->quiz()->selectedItem() == Q_NULLPTR)
            lecture->quiz()->forward();
        currentContent = lecture->quiz();
        enableControls();
        updateView();
    }
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
    ui->butQuiz->setEnabled(currentContent->canQuiz());
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
            int percent = (int)(item->progress() * 100);
            QString str = item->name();
            str.append(" (");
            str.append(QString::number(percent));
            str.append("%)");
            ui->selectorList->addItem(str);
        }
        ui->selectorList->setCurrentRow(currentContent->selectedIndex());
        navigator->setSize(0);
    }
    else if (currentContent->viewType() == ContentViewType::SlideView) {
        if (ui->stackedWidget->currentIndex() != 1)
            ui->stackedWidget->setCurrentIndex(1);
        ContentItem *item = currentContent->selectedItem();
        if (item != Q_NULLPTR) {
            item->setProgress(1.0f);
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
        updateNavigator();
    }
    else if (currentContent->viewType() == ContentViewType::QuizView) {
        if (ui->stackedWidget->currentIndex() != 2)
            ui->stackedWidget->setCurrentIndex(2);
        ui->quizCaption->setText(currentContent->name());
        ui->questionTextArea->setText("");
        ui->questionList->clear();
        Question *item = dynamic_cast<Question*>(currentContent->selectedItem());
        if (item != Q_NULLPTR) {
            ui->questionTextArea->setText(item->description());
            foreach (QString answer, item->answers()) {
                ui->questionList->addItem(answer);
            }
        }
        updateNavigator();
    }
}

QString MainWindow::dataFolder() const
{
    return m_dataFolder;
}

void MainWindow::setDataFolder(const QString &value)
{
    if (m_dataFolder != value) {
        if (model != Q_NULLPTR) {
            model->saveProgress();
            delete model;
        }
        m_dataFolder = value;
        initModel();
        currentContent = model;
        enableControls();
        updateView();
    }
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
        else
            ui->slideImage->resetTransform();
    }
}

void MainWindow::initNavigator()
{
    navigator = new NavigatorWidget(ui->navPanel);
    navigator->setSize(0);
    QLayout *navLayout = new QHBoxLayout();
    navLayout->addWidget(navigator);
    ui->navPanel->setLayout(navLayout);
    QObject::connect(navigator, SIGNAL(selectedIndexChanged()), this, SLOT(on_selectedIndexChanged()));
}

void MainWindow::updateNavigator()
{
    int count = currentContent->items().size();
    navigator->setSize(count);
    for (int i = 0; i < count; i++)
        navigator->setValue(i, currentContent->items().at(i)->progress());
    navigator->setSelectedIndex(currentContent->selectedIndex());
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

void MainWindow::on_selectedIndexChanged()
{
    currentContent->setSelectedIndex(navigator->selectedIndex());
    enableControls();
    updateView();
}

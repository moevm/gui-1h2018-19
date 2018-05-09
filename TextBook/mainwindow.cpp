#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QDialogButtonBox>
#include <QMenu>
#include <QSettings>
#include <QApplication>
#include "Model/slide.h"
#include "Model/lecture.h"
#include "Import/xmlimporter.h"
#include "optionsdialog.h"

#define QUIZ_TITLE "Контрольные вопросы"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene();
    loadSettings();
    initModel();
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
        if (!checkQuiz())
            return;
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
    if (currentContent->viewType() == ContentViewType::QuizView) {
        int result = QMessageBox::question(this, QUIZ_TITLE,
            "Прервать выполнение контрольной работы?");
        if (result != QMessageBox::StandardButton::Yes)
            return;
    }
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
    currentContent = model;
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
        enableControls();
        updateView();
        saveSettings();
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

bool MainWindow::checkQuiz()
{
    Question* question = dynamic_cast<Question*>(currentContent->selectedItem());
    if (question != Q_NULLPTR) {
        int selectedAnswerIndex = ui->questionList->currentRow();
        if (selectedAnswerIndex < 0) {
            QMessageBox::warning(this, QUIZ_TITLE,
                "Выберите один из ответов на вопрос!");
            return false;
        }
        if (selectedAnswerIndex != question->correctAnswerIndex()) {
            question->setProgress(0.2f);
            updateNavigator();
            QMessageBox::warning(this, QUIZ_TITLE,
                "Вы ответили неправильно!");
        }
        else {
            question->setProgress(1.0f);
            updateNavigator();
            QMessageBox::warning(this, QUIZ_TITLE,
                "Вы дали правильный ответ!");
        }
        if (currentContent->selectedIndex() == currentContent->items().count() - 1) {
            Quiz *quiz = dynamic_cast<Quiz*>(currentContent);
            if (quiz != Q_NULLPTR) {
                QString str = quiz->name();
                str.append("\nПравильных ответов: ");
                str.append(QString::number(quiz->correctAnswersCount()));
                str.append(" из ");
                str.append(QString::number(quiz->items().count()));
                str.append("\nСредняя оценка: ");
                str.append(QString::number(quiz->averageMark(), 'f', 2));
                QMessageBox::information(this, QUIZ_TITLE, str);
            }
            currentContent = currentContent->parent();
        }
        else
            currentContent->forward();
    }
    return true;
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

void MainWindow::loadSettings()
{
    QSettings settings("Eltech", "TextBook");
    QString defaultDataFolder = QApplication::applicationDirPath() + "/Data";
    m_dataFolder = settings.value("dataFolder", defaultDataFolder).toString();
}

void MainWindow::saveSettings()
{
    QSettings settings("Eltech", "TextBook");
    settings.setValue("dataFolder", m_dataFolder);
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

void MainWindow::on_selectorList_customContextMenuRequested(const QPoint &pos)
{
    if (currentContent->canLevelUp())
        return;
    Course *course = dynamic_cast<Course*>(currentContent->selectedItem());
    if (course == Q_NULLPTR || course->progress() == 0.0f)
        return;
    QPoint globalPos = ui->selectorList->mapToGlobal(pos);
    QMenu menu;
    menu.addAction("Начать курс заново...", this, SLOT(on_resetProgress()));
    menu.addAction("Прогресс и оценка...", this, SLOT(on_showCourseInfo()));
    menu.exec(globalPos);
}

void MainWindow::on_resetProgress()
{
    int result = QMessageBox::question(this, windowTitle(),
        "Сбросить прогресс освоения курса и начать курс заново?");
    if (result == QMessageBox::StandardButton::Yes) {
        Course *course = dynamic_cast<Course*>(currentContent->selectedItem());
        if (course != Q_NULLPTR)
            course->setProgress(0.0f);
        updateView();
    }
}

void MainWindow::on_showCourseInfo()
{
    Course *course = dynamic_cast<Course*>(currentContent->selectedItem());
    if (course == Q_NULLPTR)
        return;
    QString str = "Учебный курс: ";
    str.append(course->name());
    str.append("\nПрогресс освоения: ");
    str.append(QString::number((int)(course->progress() * 100)));
    str.append("%\nСредняя оценка: ");
    str.append(QString::number(course->averageMark(), 'f', 2));
    QMessageBox::information(this, windowTitle(), str);
}

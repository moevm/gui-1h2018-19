#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Model/slide.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    initModel();
    ui->setupUi(this);
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
    // TODO
}

void MainWindow::on_butBackward_clicked()
{
    // TODO
}

void MainWindow::on_butLevelUp_clicked()
{
    // TODO
}

void MainWindow::on_butQuiz_clicked()
{
    // TODO
}

void MainWindow::initModel()
{
    model = new ContentModel();

    ContentPart *course = new ContentPart(model);
    course->setName("Учебный курс 1");
    course->setDescription("Описание курса 1");

    ContentPart *lecture = new ContentPart(course);
    lecture->setName("Лекция 1.1");
    lecture->setDescription("Описание лекции 1.1");

    Slide *slide = new Slide(lecture);
    slide->setName("Слайд 1.1.1");
    slide->setDescription("Текст слайда 1.1.1");

    slide = new Slide(lecture);
    slide->setName("Слайд 1.1.2");
    slide->setDescription("Текст слайда 1.1.2");

    lecture = new ContentPart(course);
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

    lecture = new ContentPart(course);
    lecture->setName("Лекция 2.1");
    lecture->setDescription("Описание лекции 2.1");

    slide = new Slide(lecture);
    slide->setName("Слайд 2.1.1");
    slide->setDescription("Текст слайда 2.1.1");
}

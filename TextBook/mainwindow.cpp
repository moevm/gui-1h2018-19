#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
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

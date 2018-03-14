#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Model/contentmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_butInfo_clicked();
    void on_butForward_clicked();
    void on_butBackward_clicked();
    void on_butLevelUp_clicked();
    void on_butQuiz_clicked();

    void on_selectorList_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    ContentModel *model;
    ContentPart *currentContent;

    void initModel();
    void enableControls();
    void updateView();
};

#endif // MAINWINDOW_H

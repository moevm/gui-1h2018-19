#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Model/contentmodel.h"
#include "navigatorwidget.h"

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
    void on_selectedIndexChanged();
    void on_selectorList_customContextMenuRequested(const QPoint &pos);
    void on_resetProgress();
    void on_showCourseInfo();

private:
    Ui::MainWindow *ui;
    ContentModel *model;
    ContentPart *currentContent;
    QGraphicsScene *scene;
    QString m_dataFolder;
    NavigatorWidget *navigator;

    void initModel();
    void enableControls();
    void updateView();

    QString dataFolder() const;
    void setDataFolder(const QString &value);
    void loadSlideImage(QString imagePath);

    bool checkQuiz();

    void initNavigator();
    void updateNavigator();

    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H

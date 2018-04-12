/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblCaption;
    QPushButton *butInfo;
    QStackedWidget *stackedWidget;
    QWidget *selectorView;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *selectorCaption;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *selectorList;
    QTextEdit *selectorTextArea;
    QWidget *slideView;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *slideCaption;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *slideImage;
    QTextEdit *slideTextArea;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *butQuiz;
    QSpacerItem *horizontalSpacer;
    QPushButton *butLevelUp;
    QPushButton *butBackward;
    QPushButton *butForward;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(911, 561);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/textbook.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lblCaption = new QLabel(centralWidget);
        lblCaption->setObjectName(QStringLiteral("lblCaption"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblCaption->sizePolicy().hasHeightForWidth());
        lblCaption->setSizePolicy(sizePolicy);
        lblCaption->setMaximumSize(QSize(16777215, 72));
        QFont font;
        font.setFamily(QStringLiteral("Century Gothic"));
        font.setPointSize(24);
        lblCaption->setFont(font);

        horizontalLayout_2->addWidget(lblCaption);

        butInfo = new QPushButton(centralWidget);
        butInfo->setObjectName(QStringLiteral("butInfo"));
        butInfo->setMinimumSize(QSize(0, 64));
        butInfo->setMaximumSize(QSize(64, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images/About40x40.png"), QSize(), QIcon::Normal, QIcon::Off);
        butInfo->setIcon(icon1);
        butInfo->setIconSize(QSize(40, 40));
        butInfo->setFlat(true);

        horizontalLayout_2->addWidget(butInfo);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        selectorView = new QWidget();
        selectorView->setObjectName(QStringLiteral("selectorView"));
        gridLayout_2 = new QGridLayout(selectorView);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        selectorCaption = new QLabel(selectorView);
        selectorCaption->setObjectName(QStringLiteral("selectorCaption"));
        selectorCaption->setMinimumSize(QSize(0, 38));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 85, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        selectorCaption->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Century Gothic"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setWeight(50);
        selectorCaption->setFont(font1);
        selectorCaption->setAutoFillBackground(true);
        selectorCaption->setIndent(8);

        verticalLayout_2->addWidget(selectorCaption);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        selectorList = new QListWidget(selectorView);
        selectorList->setObjectName(QStringLiteral("selectorList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectorList->sizePolicy().hasHeightForWidth());
        selectorList->setSizePolicy(sizePolicy2);
        selectorList->setMinimumSize(QSize(200, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Century Gothic"));
        font2.setPointSize(12);
        selectorList->setFont(font2);
        selectorList->setFrameShape(QFrame::NoFrame);
        selectorList->setFrameShadow(QFrame::Plain);
        selectorList->setLineWidth(0);
        selectorList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        selectorList->setTabKeyNavigation(true);
        selectorList->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout_3->addWidget(selectorList);

        selectorTextArea = new QTextEdit(selectorView);
        selectorTextArea->setObjectName(QStringLiteral("selectorTextArea"));
        sizePolicy2.setHeightForWidth(selectorTextArea->sizePolicy().hasHeightForWidth());
        selectorTextArea->setSizePolicy(sizePolicy2);
        selectorTextArea->setFont(font2);
        selectorTextArea->setFrameShape(QFrame::NoFrame);
        selectorTextArea->setFrameShadow(QFrame::Plain);
        selectorTextArea->setLineWidth(0);
        selectorTextArea->setUndoRedoEnabled(false);
        selectorTextArea->setReadOnly(true);

        horizontalLayout_3->addWidget(selectorTextArea);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        stackedWidget->addWidget(selectorView);
        slideView = new QWidget();
        slideView->setObjectName(QStringLiteral("slideView"));
        gridLayout_3 = new QGridLayout(slideView);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        slideCaption = new QLabel(slideView);
        slideCaption->setObjectName(QStringLiteral("slideCaption"));
        slideCaption->setMinimumSize(QSize(0, 38));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        slideCaption->setPalette(palette1);
        slideCaption->setFont(font1);
        slideCaption->setAutoFillBackground(true);
        slideCaption->setIndent(8);

        verticalLayout_3->addWidget(slideCaption);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        slideImage = new QGraphicsView(slideView);
        slideImage->setObjectName(QStringLiteral("slideImage"));
        slideImage->setFrameShape(QFrame::NoFrame);
        slideImage->setLineWidth(0);
        slideImage->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        horizontalLayout_4->addWidget(slideImage);

        slideTextArea = new QTextEdit(slideView);
        slideTextArea->setObjectName(QStringLiteral("slideTextArea"));
        sizePolicy2.setHeightForWidth(slideTextArea->sizePolicy().hasHeightForWidth());
        slideTextArea->setSizePolicy(sizePolicy2);
        slideTextArea->setFont(font2);
        slideTextArea->setFrameShape(QFrame::NoFrame);
        slideTextArea->setFrameShadow(QFrame::Plain);
        slideTextArea->setLineWidth(0);
        slideTextArea->setUndoRedoEnabled(false);
        slideTextArea->setReadOnly(true);

        horizontalLayout_4->addWidget(slideTextArea);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(slideView);

        verticalLayout->addWidget(stackedWidget);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, -1, 4, -1);
        butQuiz = new QPushButton(centralWidget);
        butQuiz->setObjectName(QStringLiteral("butQuiz"));
        butQuiz->setMinimumSize(QSize(0, 64));
        butQuiz->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images/Check40x40.png"), QSize(), QIcon::Normal, QIcon::Off);
        butQuiz->setIcon(icon2);
        butQuiz->setIconSize(QSize(40, 40));
        butQuiz->setFlat(true);

        horizontalLayout->addWidget(butQuiz);

        horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        butLevelUp = new QPushButton(centralWidget);
        butLevelUp->setObjectName(QStringLiteral("butLevelUp"));
        butLevelUp->setMinimumSize(QSize(0, 64));
        butLevelUp->setMaximumSize(QSize(64, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images/Top40x40.png"), QSize(), QIcon::Normal, QIcon::Off);
        butLevelUp->setIcon(icon3);
        butLevelUp->setIconSize(QSize(40, 40));
        butLevelUp->setFlat(true);

        horizontalLayout->addWidget(butLevelUp);

        butBackward = new QPushButton(centralWidget);
        butBackward->setObjectName(QStringLiteral("butBackward"));
        butBackward->setMinimumSize(QSize(0, 64));
        butBackward->setMaximumSize(QSize(64, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Images/Backward40x40.png"), QSize(), QIcon::Normal, QIcon::Off);
        butBackward->setIcon(icon4);
        butBackward->setIconSize(QSize(40, 40));
        butBackward->setFlat(true);

        horizontalLayout->addWidget(butBackward);

        butForward = new QPushButton(centralWidget);
        butForward->setObjectName(QStringLiteral("butForward"));
        butForward->setMinimumSize(QSize(0, 64));
        butForward->setMaximumSize(QSize(64, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Images/Forward40x40.png"), QSize(), QIcon::Normal, QIcon::Off);
        butForward->setIcon(icon5);
        butForward->setIconSize(QSize(40, 40));
        butForward->setFlat(true);

        horizontalLayout->addWidget(butForward);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        selectorList->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\213\320\271 \321\203\321\207\320\265\320\261\320\275\320\270\320\272", Q_NULLPTR));
        lblCaption->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#aa55ff;\">&nbsp;\320\255\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\275\321\213\320\271 \321\203\321\207\320\265\320\261\320\275\320\270\320\272</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        butInfo->setToolTip(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        butInfo->setText(QString());
        selectorCaption->setText(QApplication::translate("MainWindow", "View Caption", Q_NULLPTR));
        slideCaption->setText(QApplication::translate("MainWindow", "View Caption", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        butQuiz->setToolTip(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\321\213\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\321\213", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        butQuiz->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\321\213\320\265 \320\262\320\276\320\277\321\200\320\276\321\201\321\213", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        butLevelUp->setToolTip(QApplication::translate("MainWindow", "\320\232 \321\201\320\277\320\270\321\201\320\272\321\203 \320\273\320\265\320\272\321\206\320\270\320\271 \320\270\320\273\320\270 \320\272\321\203\321\200\321\201\320\276\320\262", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        butLevelUp->setText(QString());
#ifndef QT_NO_TOOLTIP
        butBackward->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\267\320\260\320\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        butBackward->setText(QString());
#ifndef QT_NO_TOOLTIP
        butForward->setToolTip(QApplication::translate("MainWindow", "\320\224\320\260\320\273\320\265\320\265", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        butForward->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

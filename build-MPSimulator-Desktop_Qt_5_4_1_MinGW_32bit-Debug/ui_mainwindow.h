/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionNew_File;
    QAction *actionSave_File;
    QAction *actionCompile_Simulate;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Editor;
    QGridLayout *gridLayout_2;
    QTextEdit *codeEditor;
    QWidget *Pipeline;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *pipelineTable;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(597, 462);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/folder_orange_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon);
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QStringLiteral("actionNew_File"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/new-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon1);
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QStringLiteral("actionSave_File"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/save_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon2);
        actionCompile_Simulate = new QAction(MainWindow);
        actionCompile_Simulate->setObjectName(QStringLiteral("actionCompile_Simulate"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/compfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompile_Simulate->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Editor = new QWidget();
        Editor->setObjectName(QStringLiteral("Editor"));
        gridLayout_2 = new QGridLayout(Editor);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        codeEditor = new QTextEdit(Editor);
        codeEditor->setObjectName(QStringLiteral("codeEditor"));
        codeEditor->setMinimumSize(QSize(551, 321));
        codeEditor->setSizeIncrement(QSize(10, 10));
        QFont font;
        font.setFamily(QStringLiteral("Courier"));
        font.setPointSize(12);
        codeEditor->setFont(font);

        gridLayout_2->addWidget(codeEditor, 0, 0, 1, 1);

        tabWidget->addTab(Editor, QString());
        Pipeline = new QWidget();
        Pipeline->setObjectName(QStringLiteral("Pipeline"));
        horizontalLayoutWidget_2 = new QWidget(Pipeline);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 551, 331));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pipelineTable = new QTableWidget(horizontalLayoutWidget_2);
        pipelineTable->setObjectName(QStringLiteral("pipelineTable"));

        horizontalLayout->addWidget(pipelineTable);

        tabWidget->addTab(Pipeline, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        mainToolBar->addAction(actionOpen_File);
        mainToolBar->addAction(actionNew_File);
        mainToolBar->addAction(actionSave_File);
        mainToolBar->addAction(actionCompile_Simulate);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", 0));
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionNew_File->setText(QApplication::translate("MainWindow", "New File", 0));
#ifndef QT_NO_TOOLTIP
        actionNew_File->setToolTip(QApplication::translate("MainWindow", "New File", 0));
#endif // QT_NO_TOOLTIP
        actionNew_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionSave_File->setText(QApplication::translate("MainWindow", "Save File", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_File->setToolTip(QApplication::translate("MainWindow", "Save File", 0));
#endif // QT_NO_TOOLTIP
        actionSave_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionCompile_Simulate->setText(QApplication::translate("MainWindow", "Compile/Simulate", 0));
#ifndef QT_NO_TOOLTIP
        actionCompile_Simulate->setToolTip(QApplication::translate("MainWindow", "Compile/Simulate", 0));
#endif // QT_NO_TOOLTIP
        codeEditor->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(Editor), QApplication::translate("MainWindow", "Editor", 0));
        tabWidget->setTabText(tabWidget->indexOf(Pipeline), QApplication::translate("MainWindow", "Pipeline", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

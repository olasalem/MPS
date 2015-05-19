/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 20 00:20:29 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionNew_File;
    QAction *actionSave_File;
    QAction *actionCompile_Simulate;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionStep_Simulation;
    QAction *actionNext_Step;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Editor;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *codeEditor;
    QWidget *Register;
    QGridLayout *gridLayout_2;
    QRadioButton *hexButton;
    QTableWidget *registerTable;
    QRadioButton *radioButton;
    QWidget *data;
    QGridLayout *gridLayout_4;
    QTableWidget *dataMemTable;
    QWidget *Pipeline;
    QGridLayout *gridLayout_3;
    QTableWidget *pipelineTable;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(597, 462);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/folder_orange_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon);
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QString::fromUtf8("actionNew_File"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/new-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon1);
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName(QString::fromUtf8("actionSave_File"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/save_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_File->setIcon(icon2);
        actionCompile_Simulate = new QAction(MainWindow);
        actionCompile_Simulate->setObjectName(QString::fromUtf8("actionCompile_Simulate"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/compfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompile_Simulate->setIcon(icon3);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionStep_Simulation = new QAction(MainWindow);
        actionStep_Simulation->setObjectName(QString::fromUtf8("actionStep_Simulation"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/Start.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon4.addFile(QString::fromUtf8(":/Icons/Start.png"), QSize(), QIcon::Normal, QIcon::On);
        icon4.addFile(QString::fromUtf8(":/Icons/Start.png"), QSize(), QIcon::Active, QIcon::On);
        actionStep_Simulation->setIcon(icon4);
        actionNext_Step = new QAction(MainWindow);
        actionNext_Step->setObjectName(QString::fromUtf8("actionNext_Step"));
        actionNext_Step->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/Next.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext_Step->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Editor = new QWidget();
        Editor->setObjectName(QString::fromUtf8("Editor"));
        horizontalLayout_3 = new QHBoxLayout(Editor);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        codeEditor = new QTextEdit(Editor);
        codeEditor->setObjectName(QString::fromUtf8("codeEditor"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(10);
        codeEditor->setFont(font);

        horizontalLayout_3->addWidget(codeEditor);

        tabWidget->addTab(Editor, QString());
        Register = new QWidget();
        Register->setObjectName(QString::fromUtf8("Register"));
        gridLayout_2 = new QGridLayout(Register);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        hexButton = new QRadioButton(Register);
        hexButton->setObjectName(QString::fromUtf8("hexButton"));

        gridLayout_2->addWidget(hexButton, 0, 1, 1, 1);

        registerTable = new QTableWidget(Register);
        registerTable->setObjectName(QString::fromUtf8("registerTable"));

        gridLayout_2->addWidget(registerTable, 0, 0, 1, 1);

        radioButton = new QRadioButton(Register);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        gridLayout_2->addWidget(radioButton, 0, 2, 1, 1);

        tabWidget->addTab(Register, QString());
        data = new QWidget();
        data->setObjectName(QString::fromUtf8("data"));
        gridLayout_4 = new QGridLayout(data);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        dataMemTable = new QTableWidget(data);
        dataMemTable->setObjectName(QString::fromUtf8("dataMemTable"));

        gridLayout_4->addWidget(dataMemTable, 0, 0, 1, 1);

        tabWidget->addTab(data, QString());
        Pipeline = new QWidget();
        Pipeline->setObjectName(QString::fromUtf8("Pipeline"));
        gridLayout_3 = new QGridLayout(Pipeline);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pipelineTable = new QTableWidget(Pipeline);
        pipelineTable->setObjectName(QString::fromUtf8("pipelineTable"));

        gridLayout_3->addWidget(pipelineTable, 0, 1, 1, 1);

        tabWidget->addTab(Pipeline, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionOpen_File);
        mainToolBar->addAction(actionNew_File);
        mainToolBar->addAction(actionSave_File);
        mainToolBar->addAction(actionCompile_Simulate);
        mainToolBar->addAction(actionStep_Simulation);
        mainToolBar->addAction(actionNext_Step);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen_File->setText(QApplication::translate("MainWindow", "Open File", 0, QApplication::UnicodeUTF8));
        actionOpen_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew_File->setText(QApplication::translate("MainWindow", "New File", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew_File->setToolTip(QApplication::translate("MainWindow", "New File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSave_File->setText(QApplication::translate("MainWindow", "Save File", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave_File->setToolTip(QApplication::translate("MainWindow", "Save File", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave_File->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionCompile_Simulate->setText(QApplication::translate("MainWindow", "Compile/Simulate", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCompile_Simulate->setToolTip(QApplication::translate("MainWindow", "Compile/Simulate", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionStep_Simulation->setText(QApplication::translate("MainWindow", "Step Simulation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionStep_Simulation->setToolTip(QApplication::translate("MainWindow", "Start step by step simulation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNext_Step->setText(QApplication::translate("MainWindow", "Next Step", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNext_Step->setToolTip(QApplication::translate("MainWindow", "Go to the next step in simulation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabWidget->setTabText(tabWidget->indexOf(Editor), QApplication::translate("MainWindow", "Editor", 0, QApplication::UnicodeUTF8));
        hexButton->setText(QApplication::translate("MainWindow", "Hexadecimal", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Decimal", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Register), QApplication::translate("MainWindow", "Registers", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(data), QApplication::translate("MainWindow", "Data Memory", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Pipeline), QApplication::translate("MainWindow", "Pipeline", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

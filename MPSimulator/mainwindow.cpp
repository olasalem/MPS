#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setEditor();
    setRegisterTable();
    QMainWindow::setWindowTitle("MPSimulator");
    //setCentralWidget(codeEditor)

}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::setEditor()
{
    highlighter =  new Highlighter(ui->codeEditor->document());
}

void MainWindow::setRegisterTable()
{
    qDebug() << "In setRegiserTable function.";

}



void MainWindow::on_toolButton_clicked()
{
    qDebug() << "Testing Click";
}

#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTextStream>

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

void MainWindow::on_actionNew_File_triggered()
{

}

void MainWindow::on_actionOpen_File_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "*.s");
    QFile file(path);
    if(file.open(QFile::Text | QFile::ReadOnly)){
        QString content = file.readAll();
        qDebug() << content;
        ui->codeEditor->setText(content);
        file.close();
    }
    else
        qDebug() << "Cannot open the file.";
}

void MainWindow::on_actionSave_File_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "*.s");
    QString content = ui->codeEditor->document()->toPlainText();
    qDebug() << content;
    QFile file(path);
    if (file.open(QIODevice::ReadWrite)){
        QTextStream data(&file);
        data << content;
        //qDebug() << data;
    }
}

#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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
    ui->tabWidget->setTabText(0, "Editor - Untitled*");
    fileSaved = false;
}

void MainWindow::setRegisterTable()
{
    //qDebug() << "In setRegiserTable function.";

}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "*.s");
    QString content = ui->codeEditor->document()->toPlainText();
    qDebug() << content;
    QFile file(path);
    if (file.open(QIODevice::ReadWrite)){
        QTextStream data(&file);
        data << content;
        ui->tabWidget->setTabText(0, "Editor - " + path);
    }
    else{
        qDebug() << "Cannot open file.";
    }

}

void MainWindow::on_actionNew_File_triggered()
{
    if(!fileSaved){
        QMessageBox msg;
        msg.setText("The file is not saved.");
        msg.setInformativeText("The file is not saved, if you proceed now the file will be destroyed. "
                               "Do You Want to continue?");
        msg.setStandardButtons(QMessageBox::Save | QMessageBox::Ok | QMessageBox::Cancel);
        msg.setDefaultButton(QMessageBox::Save);
        int response = msg.exec();
        qDebug() << "The response is " << response;
        switch(response){
        case QMessageBox::Save:
            qDebug() << response << " The Save button was pushed.";
            saveFile();
            break;
        case QMessageBox::Ok:
            ui->codeEditor->clear();
            ui->tabWidget->setTabText(0, "Editor - Untitled*");
            fileSaved = false;
            break;
        case QMessageBox::Cancel:
            break;
        }
    }
    else{
        ui->codeEditor->clear();
    }

}

void MainWindow::on_actionOpen_File_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "*.s");
    QFile file(path);
    if(file.open(QFile::Text | QFile::ReadOnly)){
        QString content = file.readAll();
        qDebug() << content;
        ui->codeEditor->setText(content);
        fileSaved = true;
        file.close();
    }
    else
        qDebug() << "Cannot open the file.";
}

void MainWindow::on_actionSave_File_triggered()
{
    saveFile();
}

void MainWindow::on_actionCompile_Simulate_triggered()
{
    if(ui->codeEditor->document()->blockCount() > 1){
        qDebug() << "Here instantation of the CPU class.";
    } else{
        QMessageBox msg;
        msg.setText("The Editor is Empty");
        msg.exec();
        qDebug() << "The Editor is empty.";
    }
}

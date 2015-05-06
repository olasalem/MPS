#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
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
    QString path = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "*.asm");
    QString content = ui->codeEditor->document()->toPlainText();
    qDebug() << content;
    QFile file(path);
    if (file.open(QFile::ReadWrite | QFile::Text | QFile::Truncate)){
        QTextStream data(&file);
        data << content;
        ui->tabWidget->setTabText(0, "Editor - " + QFileInfo(file).fileName());
    }
    else{
        qDebug() << "Cannot open file.";
    }

}

void MainWindow::addStage(int cycle, QString stage)
{
    if(cycle >= ui->pipelineTable->columnCount())
        ui->pipelineTable->insertColumn(ui->pipelineTable->columnCount());
}

int MainWindow::notifyNotSaved()
{
    QMessageBox msg;
    msg.setText("The file is not saved.");
    msg.setInformativeText("The file is not saved, if you proceed now the file will be destroyed. "
                           "Do You Want to continue?");
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Ok | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    return msg.exec();

}

void MainWindow::on_actionNew_File_triggered()
{
    if(!fileSaved && ui->codeEditor->document()->blockCount() > 1){
        switch(notifyNotSaved()){
        case QMessageBox::Save:
            saveFile();
            ui->codeEditor->clear();
            ui->tabWidget->setTabText(0, "Editor - Untitled*");
            fileSaved = false;
            break;
        case QMessageBox::Ok:
            ui->codeEditor->clear();
            ui->tabWidget->setTabText(0, "Editor - Untitled*");
            fileSaved = false;
            break;
        default: break;
        }
    }
    else{
        ui->codeEditor->clear();
    }

}

void MainWindow::on_actionOpen_File_triggered()
{
    if(!fileSaved && ui->codeEditor->document()->blockCount() > 1)
    {
       if (notifyNotSaved() == QMessageBox::Save)
           saveFile();
    }
    QString path = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "*.s *.asm");
    QFile file(path);
    if(file.open(QFile::Text | QFile::ReadOnly)){
        QString content = file.readAll();
        qDebug() << content;
        ui->codeEditor->setText(content);
        ui->tabWidget->setTabText(0, "Editor - " + QFileInfo(file).fileName());
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

MainWindow::~MainWindow()
{
   delete ui;
}

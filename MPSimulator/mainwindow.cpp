#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>

#include "mainwindow.h"
#include "cpu.h"
#include "parser.h"
#include "instruction.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isStart = true;
    setEditor();
    setRegisterTable();
    setDataMemory();
    QMainWindow::setWindowTitle("MPSimulator");
    isStart = false;
}

void MainWindow::setEditor()
{
    highlighter =  new Highlighter(ui->codeEditor->document());
    ui->tabWidget->setTabText(0, "Editor - Untitled*");
    fileSaved = false;
}

void MainWindow::setRegisterTable()
{
    if (isStart){
        registers << "$zero" << "$at" << "$v0"
                  << "$v1" << "$a0" << "$a1"
                  << "$a2" << "$a3" << "$t0"
                  << "$t1" << "$t2" << "$t3"
                  << "$t4" << "$t5" << "$t6"
                  << "$t7" << "$t8" << "$t9"
                  << "$s0" << "$s1" << "$s2"
                  << "$s3" << "$s4" << "$s5"
                  << "$s6" << "$s7" << "$s8"
                  << "$k0" << "$k1" << "$gp"
                  << "$sp" << "$fp" << "$ra";
        QStringList registerHeader;
        registerHeader << "Register" << "Value";
        ui->registerTable->setRowCount(32);
        ui->registerTable->setColumnCount(2);
        ui->registerTable->setHorizontalHeaderLabels(registerHeader);
        ui->registerTable->verticalHeader()->setVisible(false);
        ui->registerTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    for (int i = 0; i < 32; ++i){
        ui->registerTable->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->registerTable->setItem(i, 1, new QTableWidgetItem("0x" + QString::number(cpu.MyReg[i])));

    }

}

void MainWindow::setDataMemory()
{
    if (isStart){
        QStringList dataHeaders;
        dataHeaders << "Address" << "Value";
        ui->dataMemTable->setRowCount(1024);
        ui->dataMemTable->setColumnCount(2);
        ui->dataMemTable->setHorizontalHeaderLabels(dataHeaders);
        ui->dataMemTable->verticalHeader()->setVisible(false);
        ui->dataMemTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    for (int i = 0; i < 1024; i++){
        ui->dataMemTable->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
        ui->dataMemTable->setItem(i, 1, new QTableWidgetItem(QString::number(cpu.MyMem[i])));
    }

}

bool MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "*.asm");
    QString content = ui->codeEditor->document()->toPlainText();
    qDebug() << content;
    currentPath = path;
    QFile file(path);
    if (file.open(QFile::ReadWrite | QFile::Text | QFile::Truncate)){
        QTextStream data(&file);
        data << content;
        ui->tabWidget->setTabText(0, "Editor - " + QFileInfo(file).fileName());
        return true;
    }
    else{
        qDebug() << "Cannot open file.";
        return false;
    }

}


int MainWindow::notifyNotSaved()
{
    QMessageBox msg;
    msg.setText("The File Is Not Saved.");
    msg.setInformativeText("The file is not saved, if you proceed now any changes will be lost. "
                           "Do You Want to continue?");
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Yes | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    return msg.exec();

}

void MainWindow::newFile()
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

void MainWindow::openFile()
{
    if(!fileSaved && ui->codeEditor->document()->blockCount() > 1)
    {
        if (notifyNotSaved() == QMessageBox::Save)
            saveFile();
    }
    QString path = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "*.s *.asm *.txt");
    QFile file(path);
    currentPath = path;
    if(file.open(QFile::Text | QFile::ReadOnly)){
        QString content = file.readAll();
        qDebug() << content;
        ui->codeEditor->setPlainText(content);
        ui->tabWidget->setTabText(0, "Editor - " + QFileInfo(file).fileName());
        fileSaved = true;
        file.close();
    }
    else
        qDebug() << "Cannot open the file.";
}

void MainWindow::addStage(int clk)
{
    if(clk >= cpu.Units.size()){
        qDebug() << "End of the pipeline.";
        stop();
    } else {
        QStringList stages;
        stages << "IF" << "ID" << "Eec" << "Mem" << "WB";
        ui->pipelineTable->verticalHeader()->setHidden(true);
        ui->pipelineTable->horizontalHeader()->setHidden(false);
        ui->pipelineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        //for (int i = 0; i < cpu.Units.size(); i++) {
        //qDebug() << "Clock: " << clk;
        //qDebug() << "Cpu.units[clk].second: " << cpu.Units[clk].second;
        if (cpu.Units[clk].second == 1)
        {   ui->pipelineTable->insertRow(ui->pipelineTable->rowCount());
        }
        ui->pipelineTable->insertColumn(ui->pipelineTable->columnCount());
        ui->pipelineTable->setItem(cpu.Units[clk].first + 1 - cpu.Units[clk].second , cpu.Units[clk].first , new QTableWidgetItem(stages[cpu.Units[clk].second - 1]));
        //}
    }
}

void MainWindow::pipeLine()
{
    QStringList stages;
    stages << "IF" << "ID" << "Exec" << "Mem" << "WB";
    ui->pipelineTable->verticalHeader()->setHidden(true);
    ui->pipelineTable->horizontalHeader()->setHidden(false);
    ui->pipelineTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (int i = 0; i < cpu.Units.size(); i++){
        if (cpu.Units[i].second == 1)
        {   ui->pipelineTable->insertRow(ui->pipelineTable->rowCount());
        }
        ui->pipelineTable->insertColumn(ui->pipelineTable->columnCount());
        ui->pipelineTable->setItem(cpu.Units[i].first + 1 - cpu.Units[i].second , cpu.Units[i].first , new QTableWidgetItem(stages[cpu.Units[i].second - 1]));
    }
}
void MainWindow::stop()
{
    ui->actionNext_Step->setEnabled(false);
    ui->actionCompile_Simulate->setEnabled(true);
    QMessageBox msg;
    msg.setText("End of pipeline");
    msg.exec();

}

void MainWindow::start()
{
    QFile file(currentPath);
    Parser parser;
    QVector <Instruction> doc = parser.parseFile(file);
    cpu.setFile(doc);
    cpu.Execute();
    //pipeLine();
    setRegisterTable();
    setDataMemory();
}

void MainWindow::startSimulation()
{
    if(ui->codeEditor->document()->blockCount() > 1){
        bool cancelled = false;
        while(!fileSaved && !cancelled){
            switch(notifyNotSaved()){
            case QMessageBox::Save:
            {
                if (!saveFile()){
                    notifyNotSaved();
                    break;
                }
            }
            case QMessageBox::Yes:
            {
                if(currentPath.isEmpty())
                {
                    QMessageBox msg;
                    msg.setText("No saved file found");
                    msg.setInformativeText("The file you are working on has no saved version, please save and try again.");
                    msg.exec();
                    notifyNotSaved();
                    break;
                }
                start();
                break;
            }
            case QMessageBox::Cancel:
                cancelled = true;
                break;
            }
        }
        if(!cancelled){
            start();
        }

    } else{
        QMessageBox msg;
        msg.setText("The Editor is Empty");
        msg.exec();
        qDebug() << "The Editor is empty.";
    }
}
/***********************ACTIONS***********************/
void MainWindow::on_actionNew_File_triggered()
{
    newFile();

}

void MainWindow::on_actionOpen_File_triggered()
{
    openFile();
}

void MainWindow::on_actionSave_File_triggered()
{
    saveFile();
}

void MainWindow::on_actionCompile_Simulate_triggered()
{
    startSimulation();
    pipeLine();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionStep_Simulation_triggered()
{
    ui->actionStep_Simulation->setDisabled(true);
    ui->Editor->setDisabled(true);
    ui->actionNext_Step->setEnabled(true);
    start();
    addStage(0);
    clock++;
}

void MainWindow::on_actionNext_Step_triggered()
{
    qDebug() << "Next step into the simulation.";

    //When finished the next button is deactivated and the start over is activated.
    //ui->actionStep_Simulation->setEnabled(true);
    //ui->actionNext_Step->setDisabled(true);
    //ui->actionCompile_Simulate->setEnabled(true);
    //ui->Editor->setEnabled(true);
    addStage(clock);
    clock++;
}
/***********Radio Buttons************************/
void MainWindow::on_hexButton_toggled(bool checked)
{
    if(checked)
        for(int i = 0; i < 32; ++i){
            ui->registerTable->setItem(i, 1, new QTableWidgetItem("0x" + QString::number(cpu.MyReg[i], 16).toUpper()));
        }
    else
        for(int i = 0; i < 32; ++i){
            ui->registerTable->setItem(i, 1, new QTableWidgetItem("0x" + QString::number(cpu.MyReg[i])));
        }

}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighter.h"
#include "cpu.h"
#include "regfile.h"
#include "datamem.h"
namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void startSimulation();
    void openFile();
    void newFile();
    void start();
private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionCompile_Simulate_triggered();

    void on_actionStep_Simulation_triggered();

    void on_actionNext_Step_triggered();

    void on_hexButton_toggled(bool checked);

private:

    bool fileSaved;
    bool stalled;
    bool isStart;
    int clock;
    Ui::MainWindow *ui;
    QString currentPath;
    QStringList registers;
    QStringList pipelineStages;
    Highlighter   *highlighter;
    CPU cpu;

    void setEditor();
    void setRegisterTable();
    void setDataMemory();
    bool saveFile();
    void addStage(int);
    void pipeLine();
    void stop();
    int notifyNotSaved();



};

#endif // MAINWINDOW_H

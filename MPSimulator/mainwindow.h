#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "highlighter.h"
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
private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionCompile_Simulate_triggered();

    void on_actionStep_Simulation_triggered();

    void on_actionNext_Step_triggered();

    void on_hexButton_toggled(bool checked);

private:

    Ui::MainWindow *ui;
    Highlighter   *highlighter;
    bool fileSaved;
    QStringList pipelineStages;
    QString currentPath;
    /*Testing*/
    QStringList registers;

    void setEditor();
    void setRegisterTable();
    void saveFile();
    void addStage();
    int notifyNotSaved();



};

#endif // MAINWINDOW_H

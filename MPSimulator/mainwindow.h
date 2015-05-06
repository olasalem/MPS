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

private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionCompile_Simulate_triggered();

private:
    Ui::MainWindow *ui;
    void setEditor();
    void setRegisterTable();
    void saveFile();
    void addStage(int cycle, QString stage);
    int notifyNotSaved();
    bool fileSaved;
    Highlighter   *highlighter;

};

#endif // MAINWINDOW_H

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
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;
    void setEditor();
    void setRegisterTable();

    Highlighter   *highlighter;

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fixturedata.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    AllData cData;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void SetupFixtureTable();



};

#endif // MAINWINDOW_H

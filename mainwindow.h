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

private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_addNewFixtureButton_clicked();

    void on_createCSVButton_clicked();

    void on_editAllButton_clicked();

private:
    Ui::MainWindow *ui;
    void SetupFixtureTable();



};

#endif // MAINWINDOW_H

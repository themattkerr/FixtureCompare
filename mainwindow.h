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
    void SetupFixtureTable();
    bool bShowMoreEditFields;
private slots:
    void on_tableWidget_cellClicked(int row, int column);

    void on_addNewFixtureButton_clicked();

    void on_createCSVButton_clicked();

    void on_editAllButton_clicked();

    void on_saveFileButton_clicked();

    void on_SortCandela_clicked();

    void on_SortLumens_clicked();



    void on_sortFixtureNameButton_clicked();

private:
    Ui::MainWindow *ui;


    int nMinimumLength;
    int nMultiplyingFactorForColumns;


};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "constsants.h"
#include "ui_mainwindow.h"
#include "startupdialog.h"
#include "fixturedata.h"
#include "fixtruecalculations.h"
#include "fixtureeditdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!(cData.bInitialized))
    {
        cData.bInitialized = true;
        startUpDialog *HowManyStart = new startUpDialog (this, &cData);
        HowManyStart->exec();
    }
    if(cData.nNumberOfFixtures == 1)
    {
        cData.nCurrentFixture = 1;
        FixtureEditDialog *AddEdit = new FixtureEditDialog (this, &cData);
        AddEdit->exec();
    }
    SetupFixtureTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupFixtureTable()
{
    ui->tableWidget->setColumnCount(NUM_FIELDS_SHOWN_IN_MAIN_TABLE);
    QStringList qstrlFieldHeaders;
    qstrlFieldHeaders << "Fixture Name" << "Candela" << "Lumens";
    ui->tableWidget->setHorizontalHeaderLabels(qstrlFieldHeaders);

    ui->tableWidget->setRowCount(cData.nNumberOfFixtures);

    for (cData.nCurrentFixture=1; cData.nCurrentFixture <= cData.nNumberOfFixtures; cData.nCurrentFixture++)
    {
        int nColumn = 0;
        ui->tableWidget->setItem(cData.nCurrentFixture-1, nColumn, new QTableWidgetItem((cData.Fixture[cData.nCurrentFixture].getFixtureName())));
        ui->tableWidget->setItem(cData.nCurrentFixture-1, ++nColumn, new QTableWidgetItem((cData.Fixture[cData.nCurrentFixture].getCandela())));
        ui->tableWidget->setItem(cData.nCurrentFixture-1, ++nColumn, new QTableWidgetItem((cData.Fixture[cData.nCurrentFixture].getLumens())));

    }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    cData.nCurrentFixture = (row + 1);
    FixtureEditDialog *AddEdit = new FixtureEditDialog (this, &cData);
    AddEdit->exec();
    SetupFixtureTable();
}

void MainWindow::on_addNewFixtureButton_clicked()
{
    cData.nNumberOfFixtures++;
    cData.nCurrentFixture = cData.nNumberOfFixtures;
    FixtureEditDialog *AddEdit = new FixtureEditDialog (this, &cData);
    AddEdit->exec();
    SetupFixtureTable();
}

void MainWindow::on_createCSVButton_clicked()
{
    SaveToFile(cData);
}

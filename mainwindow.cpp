#include "mainwindow.h"
#include "constsants.h"
#include "ui_mainwindow.h"
#include "startupdialog.h"
#include "fixturedata.h"
#include "fixtruecalculations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (!(cData.bInitialized))
    {
        startUpDialog *HowManyStart = new startUpDialog (this, &cData);
        HowManyStart->exec();
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

/*
    for (int iii = 1; iii <= 3;iii++)//cData.nNumberOfFixtures
    {
        for (int jjj = 0; iii < NUM_FIELDS_SHOWN_IN_MAIN_TABLE;jjj++)
        {
            // table assignments here...
        }
    }
*/
}

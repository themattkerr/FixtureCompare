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

    SetupFixtureTable(cData);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupFixtureTable(AllData &cData)
{
    ui->tableWidget->setColumnCount(NUM_FIELDS_SHOWN_IN_MAIN_TABLE);
    QStringList qstrlFieldHeaders;
    qstrlFieldHeaders << "Fixture Name" << "Candela" << "Lumens";
    ui->tableWidget->setHorizontalHeaderLabels(qstrlFieldHeaders);

    ui->tableWidget->setRowCount(cData.nNumberOfFixtures);

    for (int iii = 0; iii < cData.nNumberOfFixtures;iii++)
    {
        for (jjj = 0; iii < NUM_FIELDS_SHOWN_IN_MAIN_TABLE;jjj++)
        {
            // table assignments here...
        }
    }

}

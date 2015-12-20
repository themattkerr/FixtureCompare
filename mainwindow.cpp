#include "mainwindow.h"
#include "constsants.h"
#include "ui_mainwindow.h"
#include "startupdialog.h"
#include "fixturedata.h"
#include "fixtureeditdialog.h"
#include "editallfixtures.h"
#include "csvdialog.h"
#include "saveandquitdialog.h"
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bShowMoreEditFields = false;
    nMinimumLength = 15;
    nMultiplyingFactorForColumns = 7;

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

    if (cData.bUnsavedInfo == true)
    {
        SaveAndQuitDialog *cSaveAndQuit = new SaveAndQuitDialog(this, &cData);
        cSaveAndQuit->exec();
    }
    delete ui;
}

void MainWindow::SetupFixtureTable()
{
    ui->centralWidget->show();
    ui->tableWidget->setColumnCount(NUM_FIELDS_SHOWN_IN_MAIN_TABLE);
    QStringList qstrlFieldHeaders;
    qstrlFieldHeaders << "Fixture Name" << "Candela" << "Lumens";
    ui->tableWidget->setHorizontalHeaderLabels(qstrlFieldHeaders);

    ui->tableWidget->setRowCount(cData.nNumberOfFixtures);

    int nLargestStringLength = nMinimumLength;
    for (int nFixture = 1; nFixture <= cData.nNumberOfFixtures; nFixture++)
    {
        int nColumn = 0;
        nLargestStringLength = (nLargestStringLength > (cData.Fixture[nFixture].getFixtureName().size())) ? nLargestStringLength : (cData.Fixture[nFixture].getFixtureName().size() );

        ui->tableWidget->setColumnWidth(nColumn,(nLargestStringLength * nMultiplyingFactorForColumns) );


        ui->tableWidget->setItem(nFixture-1, nColumn, new QTableWidgetItem((cData.Fixture[nFixture].getFixtureName())));
        ui->tableWidget->setItem(nFixture-1, ++nColumn, new QTableWidgetItem(QLocale(QLocale::English).toString(cData.Fixture[nFixture].getValueCandela())));
        ui->tableWidget->setItem(nFixture-1, ++nColumn, new QTableWidgetItem(QLocale(QLocale::English).toString(cData.Fixture[nFixture].getValueLumens())));


    }
    if (cData.nNumberOfFixtures == MAX_NUMBER_OF_FIXTURES)
        ui->addNewFixtureButton->hide();

    cData.bAddingNewFixture = false;
    //checkNextOrLastClicked();
    //adjustSize();
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    cData.nCurrentFixture = (row + 1);
    FixtureEditDialog *AddEdit = new FixtureEditDialog (this, &cData);
    AddEdit->exec();
    SetupFixtureTable();
}
//======= Button Functions =====================================
void MainWindow::on_editAllButton_clicked()
{
    editAllFixtures *editAll = new editAllFixtures (this, &cData);
    editAll->exec();
    SetupFixtureTable();
}
void MainWindow::on_addNewFixtureButton_clicked()
{
    //ui->centralWidget->hide();
    cData.bAddingNewFixture = true;
    cData.nNumberOfFixtures++;
    cData.nCurrentFixture = cData.nNumberOfFixtures;
    FixtureEditDialog *AddEdit = new FixtureEditDialog (this, &cData);
    AddEdit->exec();
    SetupFixtureTable();
}
void MainWindow::on_saveFileButton_clicked()
{
    bool ok;
    QString filename =  QFileDialog::getSaveFileName(this, tr("Save as FixtureFile"),  "" ,tr("FixtureFile (*.fxt)"));
    ok = cData.saveAsFxt(filename);
    if (ok)
    {
        cData.bUnsavedInfo = false;
    }
    CSVDialog *CSV = new CSVDialog (this, &ok);
    CSV->exec();


}
void MainWindow::on_createCSVButton_clicked()
{
    bool ok;
    QString fileName = QFileDialog::getSaveFileName(this, tr("save File"),  "" , tr("Comma Separated Values(*.csv)"));
    ok = cData.createCSV(fileName);
    CSVDialog *CSV = new CSVDialog (this, &ok);
    CSV->exec();
}
void MainWindow::on_SortCandela_clicked()
{
    cData.sortDecendingCandela();
    SetupFixtureTable();
}
void MainWindow::on_SortLumens_clicked()
{
    cData.sortDecendingLumens();
    SetupFixtureTable();
}



#include "startupdialog.h"
#include "ui_startupdialog.h"
#include "fixturedata.h"

startUpDialog::startUpDialog(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::startUpDialog)
{
    ui->setupUi(this);
    m_cData = cData;
}

startUpDialog::~startUpDialog()
{
    delete ui;
}

void startUpDialog::on_buttonBox_accepted()
{
    int nNumOfFix=0;
    nNumOfFix = ui->spinBox->value();
    if(nNumOfFix <= MAX_NUMBER_OF_FIXTURES)
    {
        m_cData->nNumberOfFixtures = nNumOfFix;
        close();
    }
    else
    {
        ui->spinBox->setValue(1);
        ui->label->setText("ERROR!  The maximum is");
        ui->label_2->setText(QString::number(MAX_NUMBER_OF_FIXTURES,10));
    }
}

void startUpDialog::on_buttonBox_rejected()
{
    close();
}



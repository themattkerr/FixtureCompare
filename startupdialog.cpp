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
    bool ok;
    QString strNumOfFixtures = ui->spinBox->text();
    int x = strNumOfFixtures.toInt(&ok,10);
     m_cData->nNumberOfFixtures = x;
     close();
}

void startUpDialog::on_buttonBox_rejected()
{
    close();
}

void startUpDialog::on_spinBox_valueChanged(int arg1)
{


}

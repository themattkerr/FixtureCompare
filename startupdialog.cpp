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
    m_cData->nNumberOfFixtures = ui->spinBox->value();
    close();
}

void startUpDialog::on_buttonBox_rejected()
{
    close();
}



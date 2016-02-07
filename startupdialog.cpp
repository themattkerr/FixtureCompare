#include "startupdialog.h"
#include "ui_startupdialog.h"
#include "fixturedata.h"
#include "constsants.h"
#include <QDialog>
#include <QFileDialog>



startUpDialog::startUpDialog(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::startUpDialog)
{
    ui->setupUi(this);
   // setFixedSize(STARTUP_DIALOG_SIZE);
    adjustSize();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

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



void startUpDialog::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select a file"), "Files", tr("FixtureCompare File (*.fxt)") );

    m_cData->readFxt(fileName);
    close();
}

#include "confirmfixtureremovedialog.h"
#include "ui_confirmfixtureremovedialog.h"
#include "fixturedata.h"
#include "constsants.h"

ConfirmFixtureRemoveDialog::ConfirmFixtureRemoveDialog(QWidget *parent ,AllData *cData) :
    QDialog(parent),
    ui(new Ui::ConfirmFixtureRemoveDialog)
{
    ui->setupUi(this);
    //setFixedSize(CONFIRM_FIXTURE_REMOVE_SIZE);
    adjustSize();
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);

    m_cData = cData;
    ui->fixtureNum->setText(QString::number(m_cData->nCurrentFixture,10));
    ui->FixtureName->setText(m_cData->Fixture[m_cData->nCurrentFixture].getFixtureName());
}

ConfirmFixtureRemoveDialog::~ConfirmFixtureRemoveDialog()
{
    delete ui;
}

void ConfirmFixtureRemoveDialog::on_buttonBox_accepted()
{
    m_cData->bUnsavedInfo = true;
    m_cData->removeFixture(m_cData->nCurrentFixture);
    close();
}

void ConfirmFixtureRemoveDialog::on_buttonBox_rejected()
{
    close();
}

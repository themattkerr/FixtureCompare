#include "fixtureeditdialog.h"
#include "ui_fixtureeditdialog.h"
#include "QKeyEvent"
#include "fixturedata.h"
#include "commonconversions.h"
#include "mainwindow.h"


enum fixtureID
{
    EDITING = 0

};
FixtureEditDialog::FixtureEditDialog(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::FixtureEditDialog)
{
    m_cData = cData;
    ui->setupUi(this);
    m_cData->Fixture[EDITING] = m_cData->Fixture[cData->nCurrentFixture];
    setEditFieldsToCurrentState();

   // connect(ui->DistFeetSpinBox_2,SIGNAL( (double)),this,SLOT(bob(double))); <== example from tom

}
void FixtureEditDialog::keyPressEvent(QKeyEvent *evt)
{
    if(evt->key() == Qt::Key_Enter || evt->key() == Qt::Key_Return)
        return;
    QDialog::keyPressEvent(evt);
}
FixtureEditDialog::~FixtureEditDialog()
{
    delete ui;
}

void FixtureEditDialog::setEditFieldsToCurrentState()
{
    ui->FixtureNumberDisplay->setText(QString::number(m_cData->nCurrentFixture,10));

    ui->FixtureName->setText((m_cData->Fixture[EDITING].getFixtureName()));
    ui->Lumens->setText(QString::number(m_cData->Fixture[EDITING].getValueLumens(),'g',10));
    ui->CandelaBox->setText(QString::number(m_cData->Fixture[EDITING].getValueCandela(),'g',10));

    ui->DistMetersSpinBox->setValue((m_cData->Fixture[EDITING].getValueDistanceMeters()));
    ui->DistFeetSpinBox_2->setValue(( m_cData->Fixture[EDITING].getValueDistanceFeet()));

    ui->LuxSpinBox->setValue((m_cData->Fixture[EDITING].getValueLux()));
    ui->FootCandleSpinBox->setValue((m_cData->Fixture[EDITING].getValueFootCandles()));

    ui->BeamSizeMetersSpinBox_2->setValue((m_cData->Fixture[EDITING].getValueFieldSizeMeters()));
    ui->BeamSizeFeetSpinBox_3->setValue((m_cData->Fixture[EDITING].getValueFieldSizeFeet()));
    ui->FieldAngleSpinBox->setValue((m_cData->Fixture[EDITING].getValueFieldAngle()));
}



void FixtureEditDialog::on_Lumens_editingFinished()
{
    bool *ok;
    m_cData->Fixture[EDITING].enterLumens((ui->Lumens->text()).toDouble(ok));
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_CandelaBox_editingFinished()
{
    bool *ok;
    m_cData->Fixture[EDITING].enterCandela((ui->CandelaBox->text().toDouble(ok)));
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_DistMetersSpinBox_editingFinished()
{
    m_cData->Fixture[EDITING].enterDistanceMeters(ui->DistMetersSpinBox->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_LuxSpinBox_editingFinished()
{
    m_cData->Fixture[EDITING].enterLux(ui->LuxSpinBox->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_FootCandleSpinBox_editingFinished()
{
    m_cData->Fixture[EDITING].enterFootcandles(ui->FootCandleSpinBox->value() );
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_BeamSizeMetersSpinBox_2_editingFinished()
{
    m_cData->Fixture[EDITING].enterFieldSizeMeters(ui->BeamSizeMetersSpinBox_2->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_BeamSizeFeetSpinBox_3_editingFinished()
{
    m_cData->Fixture[EDITING].enterFieldSizeFeet(ui->BeamSizeFeetSpinBox_3->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_FieldAngleSpinBox_editingFinished()
{
    m_cData->Fixture[EDITING].enterFieldAngle(ui->FieldAngleSpinBox->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_DistFeetSpinBox_2_editingFinished()
{
    m_cData->Fixture[EDITING].enterDistanceFeet(ui->DistFeetSpinBox_2->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_FixtureName_editingFinished()
{
    m_cData->Fixture[EDITING].enterFixtureName(ui->FixtureName->text());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_NavigationButtons_accepted()
{
    m_cData->Fixture[m_cData->nCurrentFixture] = m_cData->Fixture[EDITING];
    close();
}



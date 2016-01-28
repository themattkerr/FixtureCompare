#include "fixtureeditdialog.h"
#include "ui_fixtureeditdialog.h"
#include "QKeyEvent"
#include "fixturedata.h"
#include "mainwindow.h"
#include "confirmfixtureremovedialog.h"
#include "cassert"
#include "mattcalculations.h"


enum fixtureID
{
    EDITING = 0
};
FixtureEditDialog::FixtureEditDialog(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::FixtureEditDialog)
{
    m_cData = cData;
    m_Parent = qobject_cast<MainWindow*>(parent);
    assert(m_Parent);
    ui->setupUi(this);

   if(((MainWindow*)parentWidget())->bShowMoreEditFields)
   {

       //setFixedSize(layout()->sizeHint());
       setFixedSize(FIXTURE_EDIT_SIZE_LARGE);
       ui->showMoreButton->hide();
       ui->showLessButton->show();
   }
   else
   {

       //setFixedSize(layout()->sizeHint());
       setFixedSize(FIXTURE_EDIT_SIZE_SMALL);
       ui->showLessButton->hide();
       ui->showMoreButton->show();
   }

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
    if(m_cData->nNumberOfFixtures < 2)
    {
        ui->Next->hide();
        ui->Last->hide();
    }
    else {
        ui->Next->show();
        ui->Last->show();
    }

    ui->FixtureNumberDisplay->setText(QString::number(m_cData->nCurrentFixture,10));

    ui->FixtureName->setText((m_cData->Fixture[EDITING].getFixtureName()));
    ui->Lumens->setText(QLocale(QLocale::English).toString((m_cData->Fixture[EDITING].getValueLumens())));

    ui->CandelaBox->setText(QLocale(QLocale::English).toString(m_cData->Fixture[EDITING].getValueCandela()));

    ui->wattageSpinBox->setValue(m_cData->Fixture[EDITING].getValueWattage());
    ui->efficacySpinBox->setValue(m_cData->Fixture[EDITING].getValueEfficacy());

    ui->DistMetersSpinBox->setValue((m_cData->Fixture[EDITING].getValueDistanceMeters()));
    ui->DistFeetSpinBox_2->setValue(( m_cData->Fixture[EDITING].getValueDistanceFeet()));

    ui->LuxSpinBox->setValue((m_cData->Fixture[EDITING].getValueLux()));
    ui->FootCandleSpinBox->setValue((m_cData->Fixture[EDITING].getValueFootCandles()));

    ui->colorTempBox->setText(m_cData->Fixture[EDITING].getColorTemp());
    ui->cRISpinBox->setValue((m_cData->Fixture[EDITING].getValueCRI()));
    ui->LEDMixBox->setText((m_cData->Fixture[EDITING].getLEDMix()));

    ui->streetPriceBox->setText(doubleToCurrency(m_cData->Fixture[EDITING].getValueStreetPrice(), US_DOLLARS));
    ui->listPriceBox->setText(doubleToCurrency(m_cData->Fixture[EDITING].getValueListPrice(), US_DOLLARS));

    ui->FieldSizeMetersSpinBox->setValue((m_cData->Fixture[EDITING].getValueFieldSizeMeters()));
    ui->FieldSizeFeetSpinBox->setValue((m_cData->Fixture[EDITING].getValueFieldSizeFeet()));
    ui->FieldAngleSpinBox->setValue((m_cData->Fixture[EDITING].getValueFieldAngle()));

    ui->BeamSizeMetersSpinBox->setValue(m_cData->Fixture[EDITING].getValueBeamSizeMeters());
    ui->BeamSizeFeetSpinBox->setValue(m_cData->Fixture[EDITING].getValueBeamSizeFeet());
    ui->BeamAngleSpinBox->setValue(m_cData->Fixture[EDITING].getValueBeamAngle());

    ui->otherInfoBox->setPlainText((m_cData->Fixture[EDITING].getOtherInfo()));
}

// Field entry -----------------------------------------------------------------------

void FixtureEditDialog::on_FixtureName_editingFinished()
{
    m_cData->Fixture[EDITING].enterFixtureName(ui->FixtureName->text());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_Lumens_editingFinished()
{
    bool ok;
    double dLumenTemp = 0;
    QString qstrTemp = ui->Lumens->text();
    dLumenTemp = qstrTemp.toDouble(&ok);
    if(ok)
        if(!doubleIsEqual( m_cData->Fixture[EDITING].getValueLumens(), dLumenTemp, NUMOFDECIMALS))
            m_cData->Fixture[EDITING].enterLumens(dLumenTemp);
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_CandelaBox_editingFinished()
{
    bool ok;
    QString qstrCandelaTemp = ui->CandelaBox->text();
    double dCandlaTemp = qstrCandelaTemp.toDouble(&ok);
    if (ok)
        if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueCandela(), dCandlaTemp, NUMOFDECIMALS))
            m_cData->Fixture[EDITING].enterCandela(dCandlaTemp);
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_DistMetersSpinBox_editingFinished()
{
    if (ui->DistMetersSpinBox->value()>0)
    {
        if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueDistanceMeters(), ui->DistMetersSpinBox->value(), NUMOFDECIMALS))
            m_cData->Fixture[EDITING].enterDistanceMeters(ui->DistMetersSpinBox->value());
        setEditFieldsToCurrentState();
    }
    else { ui->DistMetersSpinBox->setValue(m_cData->Fixture[EDITING].getValueDistanceMeters());}
}
void FixtureEditDialog::on_DistFeetSpinBox_2_editingFinished()
{
    if(ui->DistFeetSpinBox_2->value() > 0)
    {
        if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueDistanceFeet(), ui->DistFeetSpinBox_2->value(), NUMOFDECIMALS))
            m_cData->Fixture[EDITING].enterDistanceFeet(ui->DistFeetSpinBox_2->value());
        setEditFieldsToCurrentState();
    }
    else { ui->DistFeetSpinBox_2->setValue(m_cData->Fixture[EDITING].getValueDistanceFeet() );}
}
void FixtureEditDialog::on_LuxSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueLux(), ui->LuxSpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterLux(ui->LuxSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_FootCandleSpinBox_editingFinished()
{
    if (!(doubleIsEqual(m_cData->Fixture[EDITING].getValueFootCandles(), ui->FootCandleSpinBox->value(), NUMOFDECIMALS)))
        m_cData->Fixture[EDITING].enterFootcandles(ui->FootCandleSpinBox->value() );
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_FieldSizeMetersSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueFieldSizeMeters(), ui->FieldSizeMetersSpinBox->value(),NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterFieldSizeMeters(ui->FieldSizeMetersSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_FieldSizeFeetSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueFieldSizeFeet(), ui->FieldSizeFeetSpinBox->value(), NUMOFDECIMALS ))
        m_cData->Fixture[EDITING].enterFieldSizeFeet(ui->FieldSizeFeetSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_FieldAngleSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueFieldAngle(), ui->FieldAngleSpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterFieldAngle(ui->FieldAngleSpinBox->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_wattageSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueWattage(), ui->wattageSpinBox->value(), NUMOFDECIMALS))
         m_cData->Fixture[EDITING].enterWattage(ui->wattageSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_efficacySpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueEfficacy(), ui->efficacySpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterEfficacy( ui->efficacySpinBox->value());
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_colorTempBox_editingFinished()
{
    if (m_cData->Fixture[EDITING].getColorTemp()!= ui->colorTempBox->text())
        m_cData->Fixture[EDITING].enterColorTemp(ui->colorTempBox->text());

    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_cRISpinBox_editingFinished()
{
    if(m_cData->Fixture[EDITING].getValueCRI() != ui->cRISpinBox->value())
        m_cData->Fixture[EDITING].enterCRI(ui->cRISpinBox->value());
}
void FixtureEditDialog::on_LEDMixBox_editingFinished()
{
    if(m_cData->Fixture[EDITING].getLEDMix() != ui->LEDMixBox->text())
        m_cData->Fixture[EDITING].enterLEDMix(ui->LEDMixBox->text());
}

void FixtureEditDialog::on_streetPriceBox_editingFinished()
{

    double dStreetPrice = usDollarsStringToDouble(ui->streetPriceBox->text());
    if(!doubleIsEqual(m_cData->Fixture[EDITING].getValueStreetPrice(), dStreetPrice, NUMOFDECIMALS ))
            m_cData->Fixture[EDITING].enterStreetPrice(dStreetPrice);
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_listPriceBox_editingFinished()
{
    double dListPrice = usDollarsStringToDouble(ui->listPriceBox->text());
    if(!doubleIsEqual(m_cData->Fixture[EDITING].getValueListPrice(), dListPrice, NUMOFDECIMALS ))
            m_cData->Fixture[EDITING].enterListPrice(dListPrice);
    setEditFieldsToCurrentState();
}

void FixtureEditDialog::on_BeamSizeMetersSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueBeamSizeMeters(), ui->BeamSizeMetersSpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterBeamSizeMeters(ui->BeamSizeMetersSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_BeamSizeFeetSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueBeamSizeFeet(), ui->BeamSizeFeetSpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterBeamSizeFeet(ui->BeamSizeFeetSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_BeamAngleSpinBox_editingFinished()
{
    if (!doubleIsEqual(m_cData->Fixture[EDITING].getValueBeamAngle(), ui->BeamAngleSpinBox->value(), NUMOFDECIMALS))
        m_cData->Fixture[EDITING].enterBeamAngle(ui->BeamAngleSpinBox->value());
    setEditFieldsToCurrentState();
}
void FixtureEditDialog::on_otherInfoBox_textChanged()
{
    m_cData->Fixture[EDITING].enterOtherInfo(ui->otherInfoBox->toPlainText());
}



// Buttons ---------------------------------------------------------------------------

void FixtureEditDialog::on_RemoveFixture_clicked()
{
    m_cData->bAddingNewFixture = false;
    ConfirmFixtureRemoveDialog *Confirm = new ConfirmFixtureRemoveDialog(this, m_cData);
    Confirm->exec();
    close();
}

void FixtureEditDialog::on_Last_clicked()
{
    m_cData->bAddingNewFixture = false;
    m_cData->Fixture[m_cData->nCurrentFixture] = m_cData->Fixture[EDITING];

    if (m_cData->nCurrentFixture == FIRST_FIXTURE)
        m_cData->nCurrentFixture = m_cData->nNumberOfFixtures;
    else
        m_cData->nCurrentFixture--;
    m_cData->Fixture[EDITING] = m_cData->Fixture[m_cData->nCurrentFixture];
    setEditFieldsToCurrentState();
    ((MainWindow*)parentWidget())->SetupFixtureTable();
    m_cData->bUnsavedInfo = true;
}

void FixtureEditDialog::on_Next_clicked()
{
    m_cData->bAddingNewFixture = false;
    m_cData->Fixture[m_cData->nCurrentFixture] = m_cData->Fixture[EDITING];
    if (m_cData->nCurrentFixture == m_cData->nNumberOfFixtures)
        m_cData->nCurrentFixture = FIRST_FIXTURE;
    else
        m_cData->nCurrentFixture++;
    m_cData->Fixture[EDITING] = m_cData->Fixture[m_cData->nCurrentFixture];
    setEditFieldsToCurrentState();
    ((MainWindow*)parentWidget())->SetupFixtureTable();
    m_cData->bUnsavedInfo = true;
}

void FixtureEditDialog::on_NavigationButtons_accepted()
{
    m_cData->bAddingNewFixture = false;
    m_cData->Fixture[m_cData->nCurrentFixture] = m_cData->Fixture[EDITING];
    m_cData->bUnsavedInfo = true;
    close();
}
void FixtureEditDialog::on_NavigationButtons_rejected()
{
    if (m_cData->bAddingNewFixture)
    {
        m_cData->bAddingNewFixture = false;
        m_cData->nCurrentFixture--;
        m_cData->nNumberOfFixtures--;
    }
    close();
}

void FixtureEditDialog::on_showLessButton_clicked()
{
    //setFixedSize(layout()->sizeHint());
    setFixedSize(FIXTURE_EDIT_SIZE_SMALL);
    ((MainWindow*)parentWidget())->bShowMoreEditFields = false;
}

void FixtureEditDialog::on_showMoreButton_clicked()
{
    //setFixedSize(layout()->sizeHint());
    setFixedSize(FIXTURE_EDIT_SIZE_LARGE);
    ((MainWindow*)parentWidget())->bShowMoreEditFields = true;
}




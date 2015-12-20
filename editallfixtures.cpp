#include "editallfixtures.h"
#include "ui_editallfixtures.h"
#include "fixturedata.h"
#include "constsants.h"




editAllFixtures::editAllFixtures(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::editAllFixtures)
{
    ui->setupUi(this);
    setFixedSize(EDIT_ALL_SIZE);
    m_cData = cData;
    m_nSelectedToEdit = 0;
    m_nEditValue = 0;
    ui->EnterInfoGroupBox->hide();

}

editAllFixtures::~editAllFixtures()
{
    delete ui;
}



void editAllFixtures::on_Lumens_clicked()
{
    m_nSelectedToEdit = LUMENS;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter lumens:");
}
void editAllFixtures::on_Candela_clicked()
{
    m_nSelectedToEdit = CANDELA;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter candela:");
}

void editAllFixtures::on_DistInMeters_clicked()
{
    m_nSelectedToEdit = DISTANCE_IN_METERS;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter distance in meters:");
}
void editAllFixtures::on_DistInFeet_clicked()
{
    m_nSelectedToEdit = DISTANCE_IN_FEET;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter distance in feet:");
}

void editAllFixtures::on_Lux_clicked()
{
    m_nSelectedToEdit = LUX;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter lux:");
}
void editAllFixtures::on_Footcandles_clicked()
{
    m_nSelectedToEdit = FOOTCANDLES;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter footcandles:");
}

void editAllFixtures::on_FieldAngle_clicked()
{
    m_nSelectedToEdit = FIELDANGLE;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter field angle:");
}
void editAllFixtures::on_FieldDiameterMeters_clicked()
{
    m_nSelectedToEdit = FIELD_DIAMETER_IN_METERS;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter field diameter in meters:");
}
void editAllFixtures::on_FieldDiameterFeet_clicked()
{
    m_nSelectedToEdit = FIELD_DIAMETER_IN_FEET;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter field diameter in feet:");
}
void editAllFixtures::on_beamDiameterMeters_clicked()
{
    m_nSelectedToEdit = BEAM_DIAMETER_IN_METERS;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter beam diameter in meters:");
}
void editAllFixtures::on_beamDiameterFeet_clicked()
{
    m_nSelectedToEdit = BEAM_DIAMETER_IN_FEET;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter beam diameter in feet:");
}
void editAllFixtures::on_beamAngleButton_clicked()
{
    m_nSelectedToEdit = BEAM_ANGLE;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter beam angle:");
}
void editAllFixtures::on_wattageButton_clicked()
{
    m_nSelectedToEdit = WATTAGE;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter wattage:");
}
void editAllFixtures::on_efficacyButton_clicked()
{
    m_nSelectedToEdit = EFFICACY;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter efficacy:");
}
void editAllFixtures::on_colorTempButton_clicked()
{
    m_nSelectedToEdit = COLOR_TEMP;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter color temperature:");
}
void editAllFixtures::on_streetPriceButton_clicked()
{
    m_nSelectedToEdit = STREET_PRICE;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter street price:");
}
void editAllFixtures::on_listPriceButton_clicked()
{
    m_nSelectedToEdit = LIST_PRICE;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter list price:");
}




void editAllFixtures::on_buttonBox_rejected()
{
    close();
}

void editAllFixtures::on_buttonBox_accepted()
{
    bool ok = 0;
    m_cData->bUnsavedInfo = true;
    QString qstrEnteredText = ui->EnterInfo->text();
    m_nEditValue = qstrEnteredText.toDouble(&ok);

    if (ok || m_nSelectedToEdit == COLOR_TEMP )
    {
        for (unsigned int iii = 1; iii <= m_cData->nNumberOfFixtures; iii++)
        {
            switch (m_nSelectedToEdit)
            {
            case LUMENS:                    {m_cData->Fixture[iii].enterLumens(m_nEditValue);           break;}
            case CANDELA:                   {m_cData->Fixture[iii].enterCandela(m_nEditValue);          break;}
            case DISTANCE_IN_METERS:        {m_cData->Fixture[iii].enterDistanceMeters(m_nEditValue);   break;}
            case DISTANCE_IN_FEET:          {m_cData->Fixture[iii].enterDistanceFeet(m_nEditValue);     break;}
            case LUX:                       {m_cData->Fixture[iii].enterLux(m_nEditValue);              break;}
            case FOOTCANDLES:               {m_cData->Fixture[iii].enterFootcandles(m_nEditValue);      break;}
            case FIELDANGLE:                {m_cData->Fixture[iii].enterFieldAngle(m_nEditValue);       break;}
            case FIELD_DIAMETER_IN_METERS:  {m_cData->Fixture[iii].enterFieldSizeMeters(m_nEditValue);  break;}
            case FIELD_DIAMETER_IN_FEET:    {m_cData->Fixture[iii].enterFieldSizeFeet(m_nEditValue);    break;}

            case WATTAGE:                   {m_cData->Fixture[iii].enterWattage(m_nEditValue);          break;}
            case EFFICACY:                  {m_cData->Fixture[iii].enterEfficacy(m_nEditValue);         break;}
            case BEAM_ANGLE:                {m_cData->Fixture[iii].enterBeamAngle(m_nEditValue);        break;}
            case BEAM_DIAMETER_IN_METERS:   {m_cData->Fixture[iii].enterBeamSizeMeters(m_nEditValue);   break;}
            case BEAM_DIAMETER_IN_FEET:     {m_cData->Fixture[iii].enterBeamSizeFeet(m_nEditValue);     break;}
            case COLOR_TEMP:                {m_cData->Fixture[iii].enterColorTemp(qstrEnteredText);     break;}
            case STREET_PRICE:              {m_cData->Fixture[iii].enterStreetPrice(m_nEditValue);      break;}
            case LIST_PRICE:                {m_cData->Fixture[iii].enterListPrice(m_nEditValue);        break;}
            }
        }// end for loop
        close();
    }// end if(ok)

    else
        ui->EnterInfo->setText("Error! Try again.");
}


#include "editallfixtures.h"
#include "ui_editallfixtures.h"
#include "fixturedata.h"




editAllFixtures::editAllFixtures(QWidget *parent, AllData *cData) :
    QDialog(parent),
    ui(new Ui::editAllFixtures)
{
    ui->setupUi(this);
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
    ui->EnterInfoGroupBox->setTitle("Enter field diameter:");
}
void editAllFixtures::on_FieldDiameterFeet_clicked()
{
    m_nSelectedToEdit = FIELD_DIAMETER_IN_FEET;
    ui->EnterInfoGroupBox->show();
    ui->EnterInfoGroupBox->setTitle("Enter field diameter in feet:");
}

void editAllFixtures::on_buttonBox_rejected()
{
    close();
}

void editAllFixtures::on_buttonBox_accepted()
{
    bool ok = 0;
    m_nEditValue = ui->EnterInfo->text().toDouble(&ok);

    if (ok)
    {
        for (int iii = 1; iii <= m_cData->nNumberOfFixtures; iii++)
        {
            switch (m_nSelectedToEdit)
            {
            case LUMENS:                    {m_cData->Fixture[iii].enterLumens(m_nEditValue); break;}
            case CANDELA:                   {m_cData->Fixture[iii].enterCandela(m_nEditValue); break;}
            case DISTANCE_IN_METERS:        {m_cData->Fixture[iii].enterDistanceMeters(m_nEditValue); break;}
            case DISTANCE_IN_FEET:          {m_cData->Fixture[iii].enterDistanceFeet(m_nEditValue); break;}
            case LUX:                       {m_cData->Fixture[iii].enterLux(m_nEditValue); break;}
            case FOOTCANDLES:               {m_cData->Fixture[iii].enterFootcandles(m_nEditValue); break;}
            case FIELDANGLE:                {m_cData->Fixture[iii].enterFieldAngle(m_nEditValue); break;}
            case FIELD_DIAMETER_IN_METERS:  {m_cData->Fixture[iii].enterFieldSizeMeters(m_nEditValue); break;}
            case FIELD_DIAMETER_IN_FEET:    {m_cData->Fixture[iii].enterFieldSizeFeet(m_nEditValue); break;}
            }
        }// end for loop
        close();
    }// end if(ok)
    else
        ui->EnterInfo->setText("Error! Try again.");
}

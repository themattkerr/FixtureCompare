#ifndef EDITALLFIXTURES_H
#define EDITALLFIXTURES_H

#include <QDialog>

#ifndef FIXTUREDATA_H
#include "fixturedata.h"
#endif  //FIXTUREDATA_H

enum Selected {
    NONE,
    LUMENS,
    CANDELA,
    DISTANCE_IN_METERS,
    DISTANCE_IN_FEET,
    LUX,
    FOOTCANDLES,
    FIELDANGLE,
    FIELD_DIAMETER_IN_METERS,
    FIELD_DIAMETER_IN_FEET,

    WATTAGE,
    EFFICACY,
    BEAM_ANGLE,
    BEAM_DIAMETER_IN_METERS,
    BEAM_DIAMETER_IN_FEET,
    COLOR_TEMP,
    STREET_PRICE,
    LIST_PRICE,
};

namespace Ui {
class editAllFixtures;
}

class editAllFixtures : public QDialog
{
    Q_OBJECT

public:
    explicit editAllFixtures(QWidget *parent = 0, AllData *cData = 0);
    ~editAllFixtures();

private slots:
    void on_DistInMeters_clicked();

    void on_Lumens_clicked();

    void on_Candela_clicked();

    void on_DistInFeet_clicked();

    void on_Lux_clicked();

    void on_Footcandles_clicked();

    void on_FieldAngle_clicked();

    void on_FieldDiameterMeters_clicked();

    void on_FieldDiameterFeet_clicked();

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_beamDiameterMeters_clicked();

    void on_beamDiameterFeet_clicked();

    void on_beamAngleButton_clicked();

    void on_wattageButton_clicked();

    void on_efficacyButton_clicked();

    void on_colorTempButton_clicked();

    void on_streetPriceButton_clicked();

    void on_listPriceButton_clicked();

private:
    Ui::editAllFixtures *ui;
    int m_nSelectedToEdit;
    int m_nEditValue;
    AllData *m_cData;
};

#endif // EDITALLFIXTURES_H

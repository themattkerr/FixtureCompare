#ifndef FIXTUREDATA
#define FIXTUREDATA

#ifndef CONSTANTS_H
#include "constsants.h"
#endif // Constants

#ifndef QDIALOG_H
#include <qdialog.h>
#endif



class FixtureData
{

public:
    FixtureData();

    ~FixtureData();

    void enterFixtureName(QString FixtureName);
    void enterCandela(double dCandela);
    void enterLumens (double dLumens);
    void enterDistanceMeters(double dDistanceMeters);
    void enterDistanceFeet(double dDistanceFeet);
    void enterLux(double dLux);
    void enterFootcandles(double dFc);
    void enterFieldAngle(double dFieldAngle);
    void enterFieldSizeMeters(double dFieldDiameterMeters);
    void enterFieldSizeFeet(double dFieldDiameterFeet);

    void enterWattage(double dWattage);  // --- New 1.1.0
    void enterEfficacy (double dEfficacy);
    void enterBeamAngle(double dBeamAngle);
    void enterBeamSizeMeters(double dBeamDiameterMeters);
    void enterBeamSizeFeet (double dBeamDiameterFeet);
    void enterColorTemp(QString qstrColorTemp);
    void enterStreetPrice(double dStreetPrice);
    void enterListPrice (double dListPrice);



    QString getFixtureName();

    double getValueCandela();
    double getValueLumens();
    double getValueDistanceMeters();
    double getValueDistanceFeet();    
    double getValueLux();
    double getValueFootCandles();
    double getValueFieldAngle();
    double getValueFieldSizeMeters();
    double getValueFieldSizeFeet();


    double getValueWattage();  // --- 1.1.0
    double getValueEfficacy();
    double getValueBeamAngle();
    double getValueBeamSizeMeters();
    double getValueBeamSizeFeet ();
    QString getColorTemp();
    double getValueStreetPrice();
    double getValueListPrice ();

    void resetValues();
    bool loadFixtureData (QDataStream &fileData);

    FixtureData &operator =  (const FixtureData &cSource);

private:

    // Fixture Data
    QString m_FixtureName, m_qstrColorTemp;
    double	m_dLumens,
            m_dCandela,
            m_dDistanceMeters,
            m_dDistanceFeet,
            m_dLux,
            m_dFc,
            m_dFieldAngle,
            m_dFieldDiameterMeters,
            m_dFieldDiameterFeet,

            m_dWattage, //-- 1.1.0
            m_dEfficacy,
            m_dBeamAngle,
            m_dBeamDiameterMeters,
            m_dBeamDiameterFeet,
            m_dStreetPrice,
            m_dListPrice;

    bool isNotValid(double dNumToTest);
    void angleCheck();

    /*
    All calculations are done in Metric.
    Anything entered in Emperial will be converted first.
    Metric calculations will then be converted to and entered as Eperial.
    */

    void calculateCandela();
    void calculateLux();
    void calculateFieldAngle();
    void calculateFieldSize();

    void calculateEfficacy();
    void calculateBeamSize();
    void caluculateBeamAngle();

    void convertDistanceFeetToMeters();
    void convertDistanceMetersToFeet();
    void convertFootcandlesToLux();
    void convertLuxToFootcandles();
    void convertFieldDiameterFeetToMeters();
    void convertFieldDiameterMetersToFeet();

    void convertBeamDiameterMetersToFeet();
    void convertBeamDiameterFeetToMeters();
};



class AllData
{
public:

    AllData();
    ~AllData();

    QString qstrSoftwareVersion;
    bool bInitialized;
    bool bUnsavedInfo;
    bool bAddingNewFixture;
    unsigned int nNumberOfFixtures;
    unsigned int nCurrentFixture;
    FixtureData Fixture[MAX_NUMBER_OF_FIXTURES+1];


    void removeFixture(unsigned int nFixtureToRemove);
    bool createCSV(QString &fileName);
    bool saveAsFxt (QString &fileName);
    bool readFxt (QString &fileName );
    void sortDecendingCandela ();
    void sortDecendingLumens();
    void sortAscendingLumens();

};



#endif // FIXTUREDATA


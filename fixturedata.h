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


    QString getFixtureName();
    QString getCandela();
    QString getLumens();
    QString getDistanceMeters();
    QString getDistanceFeet();
    QString getLux();
    QString getdFootcandles();
    QString getFieldAngle();
    QString getFieldSizeMeters();
    QString getFieldSizeFeet();

    double getValueCandela();
    double getValueLumens();
    double getValueDistanceMeters();
    double getValueDistanceFeet();    
    double getValueLux();
    double getValueFootCandles();
    double getValueFieldAngle();
    double getValueFieldSizeMeters();
    double getValueFieldSizeFeet();

    FixtureData &operator =(const FixtureData &cSource);
    //std::string PlaceCommas(double dInput, unsigned int nNumOfDecPlaces = 0);

private:

    // Fixture Data
    QString m_FixtureName;
    double	m_dCandela,
            m_dLumens,
            m_dDistanceMeters,
            m_dDistanceFeet,
            m_dLux,
            m_dFc,
            m_dFieldAngle,
            m_dFieldDiameterMeters,
            m_dFieldDiameterFeet;
    bool isNotValid(double dNumToTest);
    /*
    All calculations are done in Metric.
    Anything entered in Emperial will be converted first.
    Metric calculations will then be converted to and entered as Eperial.
    */

    void calculateCandela();
    void calculateLux();
    void calculateFieldAngle();
    void calculateFieldSize();

    void convertDistanceFeetToMeters();
    void convertDistanceMetersToFeet();
    void convertFootcandlesToLux();
    void convertLuxToFootcandles();
    void convertFieldDiameterFeetToMeters();
    void convertFieldDiameterMetersToFeet();



};


class AllData
{
public:
    bool bInitialized;
    unsigned int nNumberOfFixtures;
    unsigned int nCurrentFixture;
    FixtureData Fixture[MAX_NUMBER_OF_FIXTURES];

    AllData()
        {
            bInitialized = 0;
            nNumberOfFixtures = 0;
            nCurrentFixture = 1;
        }
    ~AllData(){}


    //remove fixture
    // sortfixtures by candela
};



#endif // FIXTUREDATA


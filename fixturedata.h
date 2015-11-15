#ifndef FIXTUREDATA
#define FIXTUREDATA

#ifndef CONSTANTS_H
#include "constsants.h"
#endif // Constants


class FixtureData
{

public:
    FixtureData();

    ~FixtureData();

    void enterFixtureName(std::string FixtureName);
    void enterCandela(double dCandela);
    void enterDistanceMeters(double dDistanceMeters);
    void enterDistanceFeet(double dDistanceFeet);
    void enterLux(double dLux);
    void enterFootcandles(double dFc);
    void enterFieldAngle(double dFieldAngle);
    void enterFieldSizeMeters(double dFieldDiameterMeters);
    void enterFieldSizeFeet(double dFieldDiameterFeet);


    std::string getFixtureName();
    std::string getCandela();
    std::string getDistanceMeters();
    std::string getDistanceFeet();
    std::string getLux();
    std::string getdFootcandles();
    std::string getFieldAngle();
    std::string getFieldSizeMeters();
    std::string getFieldSizeFeet();

    FixtureData &operator =(const FixtureData &cSource);
    friend std::ostream& operator << (std::ostream &out, FixtureData &cSource);
    std::string PlaceCommas(double dInput, unsigned int nNumOfDecPlaces = 0);

private:

    bool	m_bMeasurementSystem;

    // Fixture Data
    std::string m_FixtureName;
    double	m_dCandela,
            m_dDistanceMeters,
            m_dDistanceFeet,
            m_dLux,
            m_dFc,
            m_dFieldAngle,
            m_dFieldDiameterMeters,
            m_dFieldDiameterFeet;

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

std::ostream& operator << (std::ostream &out, FixtureData &cSource);

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
            nNumberOfFixtures = 1;
            nCurrentFixture = 1;
        }
    ~AllData(){}

    friend std::ostream &operator << (std::ostream &out, AllData &cSource);

    //remove fixture
    // sortfixtures by candela
};

std::ostream &operator << (std::ostream &out, AllData &cSource);

#endif // FIXTUREDATA


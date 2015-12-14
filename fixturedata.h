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

    double getValueCandela();
    double getValueLumens();
    double getValueDistanceMeters();
    double getValueDistanceFeet();    
    double getValueLux();
    double getValueFootCandles();
    double getValueFieldAngle();
    double getValueFieldSizeMeters();
    double getValueFieldSizeFeet();

    void resetValues();
    bool loadFixtureData (QDataStream &fileData);

    FixtureData &operator =  (const FixtureData &cSource);

private:

    // Fixture Data
    QString m_FixtureName;
    double	m_dLumens,
            m_dCandela,
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
    QString qstrSoftwareVersion;
    bool bInitialized;
    bool bUnsavedInfo;
    bool bAddingNewFixture;
    //bool bNextClicked;
    //bool bLastClicked;
    unsigned int nNumberOfFixtures;
    unsigned int nCurrentFixture;
    FixtureData Fixture[MAX_NUMBER_OF_FIXTURES+1];

    AllData()
        {
            bInitialized = 0;
            bUnsavedInfo = false;
            bAddingNewFixture = false;
            //bNextClicked = false;
            //bLastClicked = false;
            nNumberOfFixtures = 0;
            nCurrentFixture = 1;
        }
    ~AllData(){}
    void removeFixture(unsigned int nFixtureToRemove);
    bool createCSV(QString &fileName);
    bool saveAsFxt (QString &fileName);
    bool readFxt (QString &fileName );
    void sortDecendingCandela ();
    void sortDecendingLumens();
    void sortAscendingLumens();

};



#endif // FIXTUREDATA


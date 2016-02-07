
#include <iostream>
#include <cmath>
#include <cassert>
#include "constsants.h"
#include "fixtureData.h"


#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

//public functions -----------------------------------------------------------------------------------------------------------------

    FixtureData::FixtureData()
    {
        resetValues();

    }

    FixtureData::~FixtureData(){}

    void FixtureData::enterFixtureName(QString FixtureName)	{m_FixtureName = FixtureName;}
    void FixtureData::enterCandela(double dCandela)
    {
        assert (dCandela >= 0);
        m_dCandela =  dCandela;
        calculateLux();
        convertLuxToFootcandles();
    }
    void FixtureData::enterLumens(double dLumens)
    {
        assert (dLumens >= 0);
        m_dLumens = dLumens;
        calculateEfficacy();
    }
    void FixtureData::enterDistanceMeters(double dDistanceMeters)
    {
        assert (dDistanceMeters > 0);
        m_dDistanceMeters = dDistanceMeters;
        convertDistanceMetersToFeet();
        calculateLux();
        convertLuxToFootcandles();
        calculateFieldSize();
        calculateBeamSize();
    }
    void FixtureData::enterDistanceFeet(double dDistanceFeet)
    {
        assert (dDistanceFeet > 0);
        m_dDistanceFeet = dDistanceFeet;
        convertDistanceFeetToMeters();
        calculateLux();
        convertLuxToFootcandles();
        calculateFieldSize();
        calculateBeamSize();
    }
    void FixtureData::enterLux(double dLux)
    {
        assert (dLux >= 0);
        m_dLux = dLux;
        convertLuxToFootcandles();
        calculateCandela();
    }
    void FixtureData::enterFootcandles(double dFc)
    {
        assert(dFc >= 0);
        m_dFc = dFc;
        convertFootcandlesToLux();
        calculateCandela();
    }
    void FixtureData::enterFieldAngle(double dFieldAngle)
    {
        assert (dFieldAngle >= 0);
        m_dFieldAngle = dFieldAngle;
        calculateFieldSize();
        if(!angleCheck())
            displayAngleWarning();
    }
    void FixtureData::enterFieldSizeMeters(double dFieldDiameterMeters)
    {
        assert (dFieldDiameterMeters >= 0);
        m_dFieldDiameterMeters = dFieldDiameterMeters;
        convertFieldDiameterMetersToFeet();
        calculateFieldAngle();
        if(!angleCheck())
            displayAngleWarning();
    }
    void FixtureData::enterFieldSizeFeet(double dFieldDiameterFeet)
    {
        assert (dFieldDiameterFeet >= 0);
        m_dFieldDiameterFeet = dFieldDiameterFeet;
        convertFieldDiameterFeetToMeters();
        calculateFieldAngle();
        if(!angleCheck())
            displayAngleWarning();
    }

    void FixtureData::enterWattage(double dWattage)
    {
        assert(dWattage >= 0);
        m_dWattage = dWattage;
        calculateEfficacy();
    }
    void FixtureData::enterEfficacy (double dEfficacy)
    {
        assert(dEfficacy >= 0);
        m_dEfficacy = dEfficacy;
        if(m_dLumens == 0 && m_dWattage > 0)            {m_dLumens = m_dWattage * m_dEfficacy;}
        else if(m_dLumens > 0)                          {m_dWattage = m_dLumens / m_dEfficacy;}

        else {m_dWattage = DEFAULT_WATTAGE; m_dLumens = DEFAULT_LUMENS;}
    }
    void FixtureData::enterBeamAngle(double dBeamAngle)
    {
        assert (dBeamAngle >= 0);
        m_dBeamAngle = dBeamAngle;
        calculateBeamSize();
        if(!angleCheck())
            displayAngleWarning();
    }
    void FixtureData::enterBeamSizeMeters(double dBeamDiameterMeters)
    {
        assert(dBeamDiameterMeters >= 0);
        m_dBeamDiameterMeters = dBeamDiameterMeters;
        convertBeamDiameterMetersToFeet();
        caluculateBeamAngle();
        if(!angleCheck())
            displayAngleWarning();
    }
    void FixtureData::enterBeamSizeFeet (double dBeamDiameterFeet)
    {
        assert(m_dBeamDiameterFeet >= 0);
        m_dBeamDiameterFeet = dBeamDiameterFeet;
        convertBeamDiameterFeetToMeters();
        caluculateBeamAngle();
        if(!angleCheck())
            displayAngleWarning();
    }
    void FixtureData::enterColorTemp(QString qstrColorTemp)
    {
        //qstrColorTemp.remove(',');
        m_qstrColorTemp = qstrColorTemp;
    }
    void FixtureData::enterCRI(double dCRI)
    {
        m_dCRI = dCRI;
    }
    void FixtureData::enterLEDMix(QString qstrLEDMix)
    {
        m_qstrLEDMix = qstrLEDMix;
    }
    void FixtureData::enterStreetPrice(double dStreetPrice)
    {
        assert(dStreetPrice >= 0);
        m_dStreetPrice = dStreetPrice;
    }
    void FixtureData::enterListPrice (double dListPrice)
    {
        assert(dListPrice >= 0);
        m_dListPrice = dListPrice;
    }
    void FixtureData::enterOtherInfo (QString qstrOtherInfo)
    {
        m_qstrOtherInfo = qstrOtherInfo;
    }



// ================================================================= get functions
    QString FixtureData::getFixtureName(){return  m_FixtureName;}


    double FixtureData::getValueCandela()
    {
       if (isNotValid(m_dCandela))
            return DEFAULT_CANDELA;
        return m_dCandela;
    }
    double FixtureData::getValueLumens()
    {
        if (isNotValid(m_dLumens))
            return DEFAULT_LUMENS;
        return m_dLumens;
    }
    double FixtureData::getValueDistanceMeters()
    {
        if (isNotValid(m_dDistanceMeters))
            return DEFAULT_DIST_METERS;
        return m_dDistanceMeters;
    }
    double FixtureData::getValueDistanceFeet()
    {
        if (isNotValid(m_dDistanceFeet))
            return DEFAULT_DIST_FEET;
        return m_dDistanceFeet;
    }
    double FixtureData::getValueLux()
    {
        if (isNotValid(m_dLux))
            return DEFAULT_LUX;
        return m_dLux;
    }
    double FixtureData::getValueFootCandles()
    {
        if (isNotValid(m_dFc))
            return DEFAULT_FC;
        return m_dFc;
    }
    double FixtureData::getValueFieldAngle()
    {
        if (isNotValid(m_dFieldAngle))
            return DEFAULT_F_ANGLE;
        return m_dFieldAngle;
    }
    double FixtureData::getValueFieldSizeMeters()
    {
        if (isNotValid(m_dFieldDiameterMeters))
            return DEFAULT_FIELD_SIZE_METERS;
        return m_dFieldDiameterMeters;
    }
    double FixtureData::getValueFieldSizeFeet()
    {
        if(isNotValid(m_dFieldDiameterFeet))
            return DEFAULT_FIELD_SIZE_FEET;
        return m_dFieldDiameterFeet;}

    double FixtureData::getValueWattage()
    {
        if(isNotValid(m_dWattage))
                return DEFAULT_WATTAGE;
        return m_dWattage;
    }
    double FixtureData::getValueEfficacy()
    {
        if(isNotValid(m_dEfficacy))
            return DEFAULT_EFFICACY;
        return m_dEfficacy;
    }
    double FixtureData::getValueBeamAngle()
    {
        if(isNotValid(m_dBeamAngle))
            return DEFAULT_B_ANGLE;
        return m_dBeamAngle;
    }
    double FixtureData::getValueBeamSizeMeters()
    {
        if(isNotValid(m_dBeamDiameterMeters))
            return DEFAULT_BEAM_SIZE_METERS;
        return m_dBeamDiameterMeters;
    }
    double FixtureData::getValueBeamSizeFeet ()
    {
        if(isNotValid(m_dBeamDiameterFeet))
            return DEFAULT_BEAM_SIZE_FEET;
        return m_dBeamDiameterFeet;
    }

    QString FixtureData::getColorTemp()
    {
        return m_qstrColorTemp;
    }
    double FixtureData::getValueCRI()
    {
        if(isNotValid(m_dCRI))
            return DEFAULT_CRI;
        return m_dCRI;
    }
    QString FixtureData::getLEDMix()
    {
        return m_qstrLEDMix;
    }
    double FixtureData::getValueStreetPrice()
    {
        if(isNotValid(m_dStreetPrice))
            return DEFAULT_STREET_PRICE;
        return m_dStreetPrice;
    }
    double FixtureData::getValueListPrice ()
    {
        if(isNotValid(m_dListPrice))
            return DEFAULT_LIST_PRICE;
        return m_dListPrice;
    }
    QString FixtureData::getOtherInfo()
    {
        return m_qstrOtherInfo;
    }



    void FixtureData::resetValues()
    {
        m_FixtureName = DEFAULT_NAME;

        m_dLumens = DEFAULT_LUMENS,
        m_dCandela = DEFAULT_CANDELA,

        m_dDistanceMeters = DEFAULT_DIST_METERS,
        m_dDistanceFeet = DEFAULT_DIST_FEET,
        m_dLux = DEFAULT_LUX,
        m_dFc = DEFAULT_FC,

        m_dFieldAngle = DEFAULT_F_ANGLE,
        m_dFieldDiameterMeters = DEFAULT_FIELD_SIZE_METERS,
        m_dFieldDiameterFeet = DEFAULT_FIELD_SIZE_FEET;

        m_dWattage = DEFAULT_WATTAGE; //1.1.0
        m_dEfficacy = DEFAULT_EFFICACY;

        m_dBeamAngle = DEFAULT_B_ANGLE;
        m_dBeamDiameterMeters = DEFAULT_BEAM_SIZE_METERS;
        m_dBeamDiameterFeet = DEFAULT_BEAM_SIZE_FEET;

        m_qstrColorTemp = DEFAULT_COLORTEMP;
        m_dCRI = DEFAULT_CRI;
        m_qstrLEDMix = DEFAULT_LED_MIX;

        m_dStreetPrice = DEFAULT_STREET_PRICE;
        m_dListPrice = DEFAULT_LIST_PRICE;

        m_qstrOtherInfo = DEFAULT_OTHER_INFO;
    }

    bool FixtureData::isNotValid(double dNumToTest)
    {
        if (dNumToTest > 10000000|| dNumToTest <= 0)
            return true;
        return false;
    }

    FixtureData& FixtureData::operator = (const FixtureData &cSource)
    {
        m_FixtureName = cSource.m_FixtureName;
        m_dLumens = cSource.m_dLumens;
        m_dCandela = cSource.m_dCandela;
        m_dDistanceMeters = cSource.m_dDistanceMeters;
        m_dDistanceFeet = cSource.m_dDistanceFeet;
        m_dLux = cSource.m_dLux;
        m_dFc = cSource.m_dFc;
        m_dFieldAngle = cSource.m_dFieldAngle;
        m_dFieldDiameterMeters = cSource.m_dFieldDiameterMeters;
        m_dFieldDiameterFeet = cSource.m_dFieldDiameterFeet;

        m_dWattage = cSource.m_dWattage;//---1.1.0
        m_dEfficacy = cSource.m_dEfficacy;

        m_dBeamAngle = cSource.m_dBeamAngle;
        m_dBeamDiameterMeters = cSource.m_dBeamDiameterMeters;
        m_dBeamDiameterFeet = cSource.m_dBeamDiameterFeet;

        m_qstrColorTemp = cSource.m_qstrColorTemp;
        m_dCRI = cSource.m_dCRI;
        m_qstrLEDMix = cSource.m_qstrLEDMix;

        m_dStreetPrice = cSource.m_dStreetPrice;
        m_dListPrice = cSource.m_dListPrice;

        m_qstrOtherInfo = cSource.m_qstrOtherInfo;

        return *this;
    }


// private functions ----------------------------------------------------------------------------------------------------------------

    void FixtureData::calculateCandela() {m_dCandela = (m_dLux * m_dDistanceMeters * m_dDistanceMeters);}
    void FixtureData::calculateLux(){m_dLux = (m_dCandela/(m_dDistanceMeters * m_dDistanceMeters));}
    void FixtureData::calculateFieldAngle(){m_dFieldAngle = (atan (m_dFieldDiameterMeters/(2 * m_dDistanceMeters)))* 360.0 / PI;}
    void FixtureData::calculateFieldSize()
    {
        m_dFieldDiameterMeters = (( 2 * m_dDistanceMeters) * (tan(m_dFieldAngle * ((PI / 180.0)/2))));
        convertFieldDiameterMetersToFeet();
    }

    void FixtureData::calculateEfficacy()
    {
        if(m_dWattage > 0)
        {
            m_dEfficacy = m_dLumens / m_dWattage;
        }
        else
            m_dEfficacy = 0;
    }
    void FixtureData::calculateBeamSize()
    {
        m_dBeamDiameterMeters = (2 * m_dDistanceMeters * tan(m_dBeamAngle * PI / 360.0));
        convertBeamDiameterMetersToFeet();
    }
    void FixtureData::caluculateBeamAngle() {m_dBeamAngle = (atan (m_dBeamDiameterMeters / (2*m_dDistanceMeters)))*360.0 / PI;}

    void FixtureData::convertDistanceFeetToMeters() { m_dDistanceMeters =  m_dDistanceFeet / FeetPerMeter ;}
    void FixtureData::convertDistanceMetersToFeet() {m_dDistanceFeet = m_dDistanceMeters * FeetPerMeter;}
    void FixtureData::convertFootcandlesToLux() { m_dLux =  m_dFc / LuxToFootcandleRatio;}
    void FixtureData::convertLuxToFootcandles() {m_dFc = m_dLux *  LuxToFootcandleRatio;}
    void FixtureData::convertFieldDiameterFeetToMeters() {m_dFieldDiameterMeters = m_dFieldDiameterFeet / FeetPerMeter;}
    void FixtureData::convertFieldDiameterMetersToFeet() {m_dFieldDiameterFeet = m_dFieldDiameterMeters * FeetPerMeter;}

    void FixtureData::convertBeamDiameterMetersToFeet() {m_dBeamDiameterFeet = m_dBeamDiameterMeters * FeetPerMeter;}
    void FixtureData::convertBeamDiameterFeetToMeters() {m_dBeamDiameterMeters = m_dBeamDiameterFeet / FeetPerMeter;}

    bool FixtureData::angleCheck()
    {
        if (m_dBeamAngle > m_dFieldAngle)
        {
            return false;
        }
        else
            return true;
    }

    void FixtureData::displayAngleWarning()
    {
            QMessageBox mbAngleError;
            mbAngleError.setWindowTitle("Angle Error");
            mbAngleError.setText("Warning! \nBeam angle is greater than field angle!");
            mbAngleError.exec();
    }

    // AllData Functions =============================================================================================================


    AllData::AllData()
    {
        bInitialized = 0;
        bUnsavedInfo = false;
        bAddingNewFixture = false;
        nNumberOfFixtures = 0;
        nCurrentFixture = 1;
    }
    AllData::~AllData()
    {}

    void AllData::removeFixture(unsigned int nFixtureToRemove)
    {
        assert (nFixtureToRemove > 0 && nFixtureToRemove <= nNumberOfFixtures);
        if(nFixtureToRemove == nNumberOfFixtures)
        {
            Fixture[nFixtureToRemove].resetValues();
            nNumberOfFixtures--;
            return;
        }

        for (unsigned int nAfter = nFixtureToRemove; nAfter < nNumberOfFixtures; nAfter++)
            Fixture[nAfter] = Fixture[nAfter + 1];

        Fixture[nNumberOfFixtures].resetValues();
        nNumberOfFixtures--;
        return;

    }
    void AllData::copyToNewFixture()
    {
        nNumberOfFixtures++;
        Fixture[nNumberOfFixtures] = Fixture[nCurrentFixture];
        Fixture[nNumberOfFixtures].enterFixtureName((Fixture[nNumberOfFixtures].getFixtureName().append(" - (Copy)")));


    }

    bool AllData::createCSV(QString &fileName)
    {

        QFile file (fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {
            QTextStream stream (&file);

            stream   << "Number of fixtures = ," << nNumberOfFixtures << endl;
            stream
                << "Fixture Name ,Lumens ,Candela,Wattage,Efficacy,Distance in meters,Distance in Feet,Lux,Footcandles,Field Angle,Field Diameter In Meters,Field Diameter In Feet,Beam Angle,Beam Diameter In Meters,Beam Diameter In Feet,Color Temperature,CRI,LED Mix,Street Price,List Price,Other Info" << endl;

                for (unsigned int iii =1; iii <= nNumberOfFixtures; iii++)
                {
            stream
                << Fixture [iii].getFixtureName()			<<","
                << Fixture [iii].getValueLumens()           <<","
                << Fixture [iii].getValueCandela()			<<","
                << Fixture [iii].getValueWattage()          <<","
                << Fixture [iii].getValueEfficacy()         <<","
                << Fixture [iii].getValueDistanceMeters()	<<","
                << Fixture [iii].getValueDistanceFeet()		<<","
                << Fixture [iii].getValueLux()              <<","
                << Fixture [iii].getValueFootCandles()		<<","
                << Fixture [iii].getValueFieldAngle()		<<","
                << Fixture [iii].getValueFieldSizeMeters()	<<","
                << Fixture [iii].getValueFieldSizeFeet()	<<","
                << Fixture [iii].getValueBeamAngle()        <<","
                << Fixture [iii].getValueBeamSizeMeters()   <<","
                << Fixture [iii].getValueBeamSizeFeet()     <<","
                << Fixture [iii].getColorTemp().remove(',') <<","
                << Fixture [iii].getValueCRI()              <<","
                << Fixture [iii].getLEDMix().remove(',')    <<","
                << Fixture [iii].getValueStreetPrice()      <<","
                << Fixture [iii].getValueListPrice()        <<","
                << Fixture [iii].getOtherInfo().remove(',').replace("\n", " --- ").simplified()

                << endl;
                }
            stream.flush();
        }
        else {return false;}


        return true;
    }
    bool AllData::saveAsFxt (QString &fileName )
    {
        QFile file (fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {
            QDataStream stream (&file);


            stream << QString (VERSION);
            stream << nNumberOfFixtures;

                for (unsigned int iii =1; iii <= nNumberOfFixtures; iii++)
                {

                stream << QString (Fixture [iii].getFixtureName());
                stream << (double) Fixture [iii].getValueLumens();
                stream << (double) Fixture [iii].getValueCandela();
                stream << (double) Fixture [iii].getValueDistanceMeters();
                stream << (double) Fixture [iii].getValueDistanceFeet();
                stream << (double) Fixture [iii].getValueLux();
                stream << (double) Fixture [iii].getValueFootCandles();
                stream << (double) Fixture [iii].getValueFieldAngle();
                stream << (double) Fixture [iii].getValueFieldSizeMeters();
                stream << (double) Fixture [iii].getValueFieldSizeFeet();

                stream << (double) Fixture [iii].getValueWattage();
                stream << (double) Fixture [iii].getValueEfficacy();
                stream << (double) Fixture [iii].getValueBeamAngle();
                stream << (double) Fixture [iii].getValueBeamSizeMeters();
                stream << (double) Fixture [iii].getValueBeamSizeFeet();
                stream << (QString)Fixture [iii].getColorTemp();
                stream << (double) Fixture [iii].getValueCRI();
                stream << (QString)Fixture [iii].getLEDMix();
                stream << (double) Fixture [iii].getValueStreetPrice();
                stream << (double) Fixture [iii].getValueListPrice();
                stream << (QString)Fixture [iii].getOtherInfo();

                }
           file.flush();
           file.close();
           return true;
        }
       else
            return false;
}
    bool AllData::readFxt (QString &fileName )
    {

        QFile file (fileName);
        file.open(QIODevice::ReadOnly);

            QDataStream stream (&file);

           stream >> qstrSoftwareVersion;

           if(qstrSoftwareVersion == "1.0.0")//<----------------------------Read 1.0.0
           {
           stream >> nNumberOfFixtures;
           for (unsigned int i = 1; i <= nNumberOfFixtures; i++)
           {

                QString qstrFixtName;
                double dLumens,dCandela,dDistMeter,dDistFeet,dLux,dFc,dFAngle,dSizeMeter,dSizeFeet;

                stream >> qstrFixtName;
                stream >> dLumens >> dCandela >> dDistMeter >> dDistFeet >> dLux >> dFc >> dFAngle >> dSizeMeter >> dSizeFeet;

                Fixture[i].enterFixtureName(qstrFixtName);
                Fixture[i].enterLumens(dLumens);
                Fixture[i].enterCandela(dCandela);
                Fixture[i].enterDistanceMeters(dDistMeter);
                Fixture[i].enterDistanceFeet(dDistFeet);
                Fixture[i].enterLux(dLux);
                Fixture[i].enterFootcandles(dFc);
                Fixture[i].enterFieldAngle(dFAngle);
                Fixture[i].enterFieldSizeMeters(dSizeMeter);
                Fixture[i].enterFieldSizeFeet(dSizeFeet);
            }
           file.close();
           return true;
          }
         if(qstrSoftwareVersion == "1.1.0")//<----------------------------Read 1.1.0
         {
             stream >> nNumberOfFixtures;
             for (unsigned int i = 1; i <= nNumberOfFixtures; i++)
             {

                  QString qstrFixtName, qstrColorTemp;
                  double dLumens,dCandela,dDistMeter,dDistFeet,dLux,dFc,dFAngle,dSizeMeter,dSizeFeet, dWattage, dEfficacy, dBAngle, dBSizeMeter, dBSizeFeet, dStreet, dList;

                  stream >> qstrFixtName;
                  stream >> dLumens >> dCandela >> dDistMeter >> dDistFeet >> dLux >> dFc >> dFAngle
                         >> dSizeMeter >> dSizeFeet >> dWattage >> dEfficacy >> dBAngle >> dBSizeMeter >> dBSizeFeet
                         >> qstrColorTemp >> dStreet >> dList  ;

                  Fixture[i].enterFixtureName(qstrFixtName);
                  Fixture[i].enterLumens(dLumens);
                  Fixture[i].enterCandela(dCandela);
                  Fixture[i].enterDistanceMeters(dDistMeter);
                  Fixture[i].enterDistanceFeet(dDistFeet);
                  Fixture[i].enterLux(dLux);
                  Fixture[i].enterFootcandles(dFc);
                  Fixture[i].enterFieldAngle(dFAngle);
                  Fixture[i].enterFieldSizeMeters(dSizeMeter);
                  Fixture[i].enterFieldSizeFeet(dSizeFeet);

                  Fixture[i].enterWattage(dWattage);
                  Fixture[i].enterEfficacy(dEfficacy);
                  Fixture[i].enterBeamAngle(dBAngle);
                  Fixture[i].enterBeamSizeMeters(dBSizeMeter);
                  Fixture[i].enterBeamSizeFeet(dBSizeFeet);
                  Fixture[i].enterColorTemp(qstrColorTemp);
                  Fixture[i].enterStreetPrice(dStreet);
                  Fixture[i].enterListPrice(dList);




              }
             file.close();
             return true;
         }
         if(qstrSoftwareVersion == "1.1.1" || qstrSoftwareVersion == "1.1.2" || qstrSoftwareVersion == "1.1.3"  || qstrSoftwareVersion == "1.1.4")
         {
             stream >> nNumberOfFixtures;
             for (unsigned int i = 1; i <= nNumberOfFixtures; i++)
             {

                  QString qstrFixtName, qstrColorTemp, qstrLEDMix, qstrOtherInfo;
                  double dLumens,dCandela,dDistMeter,dDistFeet,dLux,dFc,dFAngle,dSizeMeter,dSizeFeet, dWattage, dEfficacy, dBAngle, dBSizeMeter, dBSizeFeet, dCRI, dStreet, dList;

                  stream >> qstrFixtName;
                  stream >> dLumens >> dCandela >> dDistMeter >> dDistFeet >> dLux >> dFc >> dFAngle
                         >> dSizeMeter >> dSizeFeet >> dWattage >> dEfficacy >> dBAngle >> dBSizeMeter >> dBSizeFeet
                         >> qstrColorTemp >> dCRI >> qstrLEDMix >> dStreet >> dList >> qstrOtherInfo ;

                  Fixture[i].enterFixtureName(qstrFixtName);
                  Fixture[i].enterLumens(dLumens);
                  Fixture[i].enterCandela(dCandela);
                  Fixture[i].enterDistanceMeters(dDistMeter);
                  Fixture[i].enterDistanceFeet(dDistFeet);
                  Fixture[i].enterLux(dLux);
                  Fixture[i].enterFootcandles(dFc);
                  Fixture[i].enterFieldAngle(dFAngle);
                  Fixture[i].enterFieldSizeMeters(dSizeMeter);
                  Fixture[i].enterFieldSizeFeet(dSizeFeet);

                  Fixture[i].enterWattage(dWattage);
                  Fixture[i].enterEfficacy(dEfficacy);
                  Fixture[i].enterBeamAngle(dBAngle);
                  Fixture[i].enterBeamSizeMeters(dBSizeMeter);
                  Fixture[i].enterBeamSizeFeet(dBSizeFeet);
                  Fixture[i].enterColorTemp(qstrColorTemp);
                  Fixture[i].enterCRI(dCRI);
                  Fixture[i].enterLEDMix(qstrLEDMix);
                  Fixture[i].enterStreetPrice(dStreet);
                  Fixture[i].enterListPrice(dList);
                  Fixture[i].enterOtherInfo(qstrOtherInfo);



              }
             file.close();
             return true;
         }
        file.close();
        return false;
    }

    void AllData::sortAscendingFixtureName()
    {
        for (unsigned int nStartIndex = 1; nStartIndex <= nNumberOfFixtures; nStartIndex++)
            for (unsigned int nTest = nStartIndex+1; nTest <= nNumberOfFixtures; nTest++)
            {
                if (Fixture[nStartIndex].getFixtureName() > Fixture[nTest].getFixtureName())
                {
                    Fixture[0] = Fixture[nStartIndex];
                    Fixture[nStartIndex] = Fixture[nTest];
                    Fixture[nTest] = Fixture[0];
                    Fixture[0].resetValues();
                }
            }
    }
    void AllData::sortDecendingCandela()
    {
        for (unsigned int nStartIndex = 1; nStartIndex <= nNumberOfFixtures; nStartIndex++)
            for (unsigned int nTest = nStartIndex+1; nTest <= nNumberOfFixtures; nTest++)
            {
                if (Fixture[nStartIndex].getValueCandela() < Fixture[nTest].getValueCandela())
                {
                    Fixture[0] = Fixture[nStartIndex];
                    Fixture[nStartIndex] = Fixture[nTest];
                    Fixture[nTest] = Fixture[0];
                    Fixture[0].resetValues();
                }
            }
       }
    void AllData::sortDecendingLumens()
    {
        for (unsigned int nStartIndex = 1; nStartIndex <= nNumberOfFixtures; nStartIndex++)
            for (unsigned int nTest = nStartIndex+1; nTest <= nNumberOfFixtures; nTest++)
            {
                if (Fixture[nStartIndex].getValueLumens() < Fixture[nTest].getValueLumens())
                {
                    Fixture[0] = Fixture[nStartIndex];
                    Fixture[nStartIndex] = Fixture[nTest];
                    Fixture[nTest] = Fixture[0];
                    Fixture[0].resetValues();
                }
            }
    }
    void AllData::sortAscendingLumens()
    {
        for (unsigned int nStartIndex = 1; nStartIndex <= nNumberOfFixtures; nStartIndex++)
            for (unsigned int nTest = nStartIndex+1; nTest <= nNumberOfFixtures; nTest++)
            {
                if (Fixture[nStartIndex].getValueLumens() > Fixture[nTest].getValueLumens())
                {
                    Fixture[0] = Fixture[nStartIndex];
                    Fixture[nStartIndex] = Fixture[nTest];
                    Fixture[nTest] = Fixture[0];
                    Fixture[0].resetValues();
                }
            }
    }

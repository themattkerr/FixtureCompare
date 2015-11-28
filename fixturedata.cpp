
#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <sstream>
#include <cmath>
#include <cassert>
#include "constsants.h"
#include "fixtureData.h"


#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QFileDialog>

//public functions -----------------------------------------------------------------------------------------------------------------

    FixtureData::FixtureData()
    {
        resetValues();
 /*
        m_FixtureName = "New Fixture";
        m_dLumens = 0,
        m_dCandela = 0,

        m_dDistanceMeters = 10,
        m_dDistanceFeet = 32.8,
        m_dLux = 0,
        m_dFc = 0,
        m_dFieldAngle = 0,
        m_dFieldDiameterMeters = 0,
        m_dFieldDiameterFeet = 0;
        */
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
    }
    void FixtureData::enterDistanceMeters(double dDistanceMeters)
    {
        assert (dDistanceMeters > 0);
        m_dDistanceMeters = dDistanceMeters;
        convertDistanceMetersToFeet();
        calculateLux();
        convertLuxToFootcandles();
        calculateFieldSize();
    }
    void FixtureData::enterDistanceFeet(double dDistanceFeet)
    {
        assert (dDistanceFeet > 0);
        m_dDistanceFeet = dDistanceFeet;
        convertDistanceFeetToMeters();
        calculateLux();
        convertLuxToFootcandles();
        calculateFieldSize();
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
    }
    void FixtureData::enterFieldSizeMeters(double dFieldDiameterMeters)
    {
        assert (dFieldDiameterMeters >= 0);
        m_dFieldDiameterMeters = dFieldDiameterMeters;
        convertFieldDiameterMetersToFeet();
        calculateFieldAngle();
    }
    void FixtureData::enterFieldSizeFeet(double dFieldDiameterFeet)
    {
        assert (dFieldDiameterFeet >= 0);
        m_dFieldDiameterFeet = dFieldDiameterFeet;
        convertFieldDiameterFeetToMeters();
        calculateFieldAngle();
    }

    QString FixtureData::getFixtureName(){return  m_FixtureName;}


    double FixtureData::getValueCandela()
    {
       if (isNotValid(m_dCandela))
            return 0;
        return m_dCandela;
    }
    double FixtureData::getValueLumens()
    {
        if (isNotValid(m_dLumens))
            return 0;
        return m_dLumens;
    }

    double FixtureData::getValueDistanceMeters()
    {
        if (isNotValid(m_dDistanceMeters))
            return 1;
        return m_dDistanceMeters;
    }

    double FixtureData::getValueDistanceFeet()
    {
        if (isNotValid(m_dDistanceFeet))
            return 3.28;
        return m_dDistanceFeet;
    }

    double FixtureData::getValueLux()
    {
        if (isNotValid(m_dLux))
            return 0;
        return m_dLux;
    }

    double FixtureData::getValueFootCandles()
    {
        if (isNotValid(m_dFc))
            return 0;
        return m_dFc;
    }

    double FixtureData::getValueFieldAngle()
    {
        if (isNotValid(m_dFieldAngle))
            return 0;
        return m_dFieldAngle;
    }

    double FixtureData::getValueFieldSizeMeters()
    {
        if (isNotValid(m_dFieldDiameterMeters))
            return 0;
        return m_dFieldDiameterMeters;
    }

    double FixtureData::getValueFieldSizeFeet()
    {
        if(isNotValid(m_dFieldDiameterFeet))
            return 0;
        return m_dFieldDiameterFeet;}

    void FixtureData::resetValues()
    {
        m_FixtureName = "New Fixture";
        m_dLumens = 0,
        m_dCandela = 0,

        m_dDistanceMeters = 10,
        m_dDistanceFeet = 32.8,
        m_dLux = 0,
        m_dFc = 0,
        m_dFieldAngle = 0,
        m_dFieldDiameterMeters = 0,
        m_dFieldDiameterFeet = 0;
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

        return *this;
    }


// private functions ----------------------------------------------------------------------------------------------------------------

    void FixtureData::calculateCandela() {m_dCandela = (m_dLux * m_dDistanceMeters * m_dDistanceMeters);}
    void FixtureData::calculateLux(){m_dLux = (m_dCandela/(m_dDistanceMeters * m_dDistanceMeters));}
    void FixtureData::calculateFieldAngle(){m_dFieldAngle = (atan (m_dFieldDiameterMeters/(2 * m_dDistanceMeters)))* 360.0 / PI;}
    void FixtureData::calculateFieldSize()
    {
        m_dFieldDiameterMeters = (2 * m_dDistanceMeters * tan(m_dFieldAngle * PI / 360.0));
        convertFieldDiameterMetersToFeet();
    }

    void FixtureData::convertDistanceFeetToMeters() { m_dDistanceMeters =  m_dDistanceFeet / FeetPerMeter ;}
    void FixtureData::convertDistanceMetersToFeet() {m_dDistanceFeet = m_dDistanceMeters * FeetPerMeter;}
    void FixtureData::convertFootcandlesToLux() { m_dLux =  m_dFc / LuxToFootcandleRatio;}
    void FixtureData::convertLuxToFootcandles() {m_dFc = m_dLux *  LuxToFootcandleRatio;}
    void FixtureData::convertFieldDiameterFeetToMeters() {m_dFieldDiameterMeters = m_dFieldDiameterFeet / FeetPerMeter;}
    void FixtureData::convertFieldDiameterMetersToFeet() {m_dFieldDiameterFeet = m_dFieldDiameterMeters * FeetPerMeter;}


    // AllData Functions =============================================================================================================

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
        {
            Fixture[nAfter] = Fixture[nAfter + 1];
            Fixture[nNumberOfFixtures].resetValues();
            nNumberOfFixtures--;
            return;
        }
    }

    bool AllData::createCSV(QString &fileName)
    {

        QFile file (fileName);
        if (file.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {
            QTextStream stream (&file);

            stream   << "Number of fixtures = ," << nNumberOfFixtures << endl;
            stream
                << "Fixture Name ,Lumens ,Candela,Distance in meters,Distance in Feet,Lux,Footcandles,Field Angle,Field Diameter In Meters,Field Diameter In Feet" << endl;

                for (unsigned int iii =1; iii <= nNumberOfFixtures; iii++)
                {
            stream
                << Fixture [iii].getFixtureName()			<<","
                << Fixture [iii].getValueLumens()           <<","
                << Fixture [iii].getValueCandela()			<<","
                << Fixture [iii].getValueDistanceMeters()	<<","
                << Fixture [iii].getValueDistanceFeet()		<<","
                << Fixture [iii].getValueLux()              <<","
                << Fixture [iii].getValueFootCandles()		<<","
                << Fixture [iii].getValueFieldAngle()		<<","
                << Fixture [iii].getValueFieldSizeMeters()	<<","
                << Fixture [iii].getValueFieldSizeFeet()	<<","

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

                }
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

            //while(!(stream.atEnd()))
            //{
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
           return true;
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

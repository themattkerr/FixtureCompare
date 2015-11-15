
#include <iostream>
#include <cmath>
#include <string>
#include "fixtureData.h"
#include "fixtruecalculations.h"
#include <cassert>
#include <sstream>

//public functions -----------------------------------------------------------------------------------------------------------------

    FixtureData::FixtureData()
    {
        m_FixtureName = "New Fixture";
        m_bMeasurementSystem = 0;
        m_dCandela = 0, m_dDistanceMeters = .001, m_dLux = 0, m_dDistanceFeet = .00328,  m_dFc = 0, m_dFieldAngle = 0, m_dFieldDiameterMeters = 0, m_dFieldDiameterFeet = 0;
    }

    FixtureData::~FixtureData(){}

    void FixtureData::enterFixtureName(std::string FixtureName)	{m_FixtureName = FixtureName;}
    void FixtureData::enterCandela(double dCandela)
    {
        assert (dCandela >= 0);
        m_dCandela =  dCandela;
        calculateLux();
        convertLuxToFootcandles();
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
        assert (dLux >=0);
        m_dLux = dLux;
        convertLuxToFootcandles();
        calculateCandela();
    }
    void FixtureData::enterFootcandles(double dFc)
    {
        assert(dFc>=0);
        m_dFc = dFc;
        convertFootcandlesToLux();
        calculateCandela();
    }
    void FixtureData::enterFieldAngle(double dFieldAngle)
    {
        m_dFieldAngle = dFieldAngle;
        calculateFieldSize();

    }
    void FixtureData::enterFieldSizeMeters(double dFieldDiameterMeters)
    {
        assert (dFieldDiameterMeters > 0);
        m_dFieldDiameterMeters = dFieldDiameterMeters;
        convertFieldDiameterMetersToFeet();
        calculateFieldAngle();
    }
    void FixtureData::enterFieldSizeFeet(double dFieldDiameterFeet)
    {
        assert (dFieldDiameterFeet > 0);
        m_dFieldDiameterFeet = dFieldDiameterFeet;
        convertFieldDiameterFeetToMeters();
        calculateFieldAngle();
    }

    std::string FixtureData::getFixtureName(){return  m_FixtureName;}

    std::string FixtureData::getCandela()
    {
        if(m_dCandela <= 0)
            return UNKNOWN;
        return PlaceCommas(m_dCandela,NUMOFDECIMALSLIGHTLEVELS);}
    std::string FixtureData::getDistanceMeters()
    {
        if (m_dDistanceMeters <= .001)
            return UNKNOWN;
        return PlaceCommas (m_dDistanceMeters, NUMOFDECIMALS);
    }
    std::string FixtureData::getDistanceFeet()
    {
        if(m_dDistanceFeet <= .00328)
            return UNKNOWN;
        return PlaceCommas (m_dDistanceFeet, NUMOFDECIMALS);
    }
    std::string FixtureData::getLux()
    {
        if (m_dLux <= 0 || m_dLux > 10000000)
            return UNKNOWN;
        return PlaceCommas(m_dLux,NUMOFDECIMALSLIGHTLEVELS) ;
    }
    std::string FixtureData::getdFootcandles()
    {
        if (m_dFc <= 0 || m_dFc  > 10000000)
            return UNKNOWN;
        return PlaceCommas(m_dFc, NUMOFDECIMALSLIGHTLEVELS) ;
    }
    std::string FixtureData::getFieldAngle()
    {
        if (m_dFieldAngle <= 0 )
            return UNKNOWN;
        return PlaceCommas(m_dFieldAngle, NUMOFDECIMALS);
    }
    std::string FixtureData::getFieldSizeMeters()
    {
        if (m_dFieldDiameterMeters <= 0)
            return UNKNOWN;
        return PlaceCommas(m_dFieldDiameterMeters, NUMOFDECIMALS);
    }
    std::string FixtureData::getFieldSizeFeet()
    {
        if (m_dFieldDiameterFeet <= 0)
            return UNKNOWN;
        return PlaceCommas(m_dFieldDiameterFeet, NUMOFDECIMALS);
    }


    /*
    double FixtureData::getCandela() {return ((static_cast<int>((100*m_dCandela) + 0.5))/100.00);}
    double FixtureData::getDistanceMeters() {return ((static_cast<int>((100*m_dDistanceMeters) + 0.5))/100.00);}
    double FixtureData::getDistanceFeet() {return (static_cast<int>((100*m_dDistanceFeet) + 0.5)/100.00);}
    double FixtureData::getLux() {return (static_cast<int>((100*m_dLux) + 0.5)/100.00);}
    double FixtureData::getdFootcandles() {return (static_cast<int> ((100*m_dFc) + 0.5)/100.00);}
    double FixtureData::getFieldAngle() {return (static_cast<int>((100*m_dFieldAngle) + 0.5)/100.00);}
    double FixtureData::getFieldSizeMeters() {return (static_cast<int>((100*m_dFieldDiameterMeters) + 0.5)/100.00);}
    double FixtureData::getFieldSizeFeet() {return (static_cast<int>((100*m_dFieldDiameterFeet) + 0.5)/100.00);}
    */
    FixtureData& FixtureData::operator= (const FixtureData &cSource)
    {
        m_FixtureName = cSource.m_FixtureName;
        m_dCandela = cSource.m_dCandela;
        m_dDistanceMeters = cSource.m_dDistanceMeters;
        m_dLux = cSource.m_dLux;
        m_dDistanceFeet = cSource.m_dDistanceFeet;
        m_dFc = cSource.m_dFc;
        m_dFieldAngle = cSource.m_dFieldAngle;
        m_dFieldDiameterMeters = cSource.m_dFieldDiameterMeters;
        m_dFieldDiameterFeet = cSource.m_dFieldDiameterFeet;

        return *this;
    }
    std::ostream& operator << (std::ostream &out, FixtureData &cSource)
    {

        out	<< cSource.m_FixtureName			<<","
            << cSource.m_dCandela				<<","
            << cSource.m_dDistanceMeters		<<","
            << cSource.m_dLux					<<","
            << cSource.m_dDistanceFeet			<<","
            << cSource.m_dFc					<<","
            << cSource.m_dFieldAngle			<<","
            << cSource.m_dFieldDiameterMeters	<<","
            << cSource.m_dFieldDiameterFeet		<<","

            << std::endl;
        /*
        out << cSource.getFixtureName() <<"\t"
            << cSource.getCandela() <<"\t"
            << cSource.getDistanceMeters() <<"\t"
            << cSource.getLux() <<"\t"
            << cSource.getDistanceFeet() <<"\t"
            << cSource.getdFootcandles() <<"\t"
            << cSource.getFieldAngle() <<"\t"
            << cSource.getFieldSizeMeters() <<"\t"
            << cSource.getFieldSizeFeet() <<"\t"


            << std::endl;
        */
        return out;
    }

    std::string FixtureData::PlaceCommas(double dInput, unsigned int nNumOfDecPlaces)
{
using namespace std;
    stringstream ConverstionStream;
    stringstream Output;
    string strNumber;
    string strCommasAdded;

    if(nNumOfDecPlaces > 0)
        for(int iii = 1;iii <= nNumOfDecPlaces; iii++)
            dInput *= 10;
    if(dInput < 0)
        dInput -= 0.5;
    else
        dInput += 0.5;

    ConverstionStream << static_cast<int>(dInput);
    ConverstionStream >> strNumber;

    int nLength = strNumber.length();

    int nIndex = (nLength - nNumOfDecPlaces);
    if (nIndex <= 0)
        nIndex = 0;

    for(int jjj = 0; jjj < (nIndex); jjj++)
    {
        if(!((nIndex - jjj)%3) && ((jjj > 0)) && !(dInput < 0 && jjj == 1))
            Output << ",";
        Output << strNumber[jjj];
    }
    if (nNumOfDecPlaces > 0)
    {
        Output << ".";
        for(int III = (nIndex); III < (nIndex+nNumOfDecPlaces); III++)
            if (nIndex)
                Output << strNumber[III];
            else
                Output << "0";
    }
    Output >> strCommasAdded;
    return strCommasAdded;
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



// AllData functions

    std::ostream &operator << (std::ostream &out, AllData &cSource)
    {

            out << "Number of fixtures = " << "," << cSource.nNumberOfFixtures << std::endl;
            out << "Maximum number of fixtures = " << "," << MAX_NUMBER_OF_FIXTURES-1 << std::endl;
            out << std::endl;


        return out;
    }



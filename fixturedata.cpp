

#include <cmath>
#include "constsants.h"
#include "fixtureData.h"
#include <cassert>
#include <QDialog>

//public functions -----------------------------------------------------------------------------------------------------------------

    FixtureData::FixtureData()
    {
        m_FixtureName = "New Fixture";

        m_dCandela = 0,
        m_dLumens = 0,
        m_dDistanceMeters = 10,
        m_dLux = 0,
        m_dDistanceFeet = 32.8,
        m_dFc = 0,
        m_dFieldAngle = 0,
        m_dFieldDiameterMeters = 0,
        m_dFieldDiameterFeet = 0;
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

    QString FixtureData::getFixtureName(){return  m_FixtureName;}

    QString FixtureData::getCandela()
    {
        if(isNotValid(m_dCandela)) // <<====================================<<<<<
            return UNKNOWN;
        return QString::number(m_dCandela,'g',0);
    }
    QString FixtureData::getLumens()
    {
        if(isNotValid (m_dLumens))
            return UNKNOWN;
        return QString::number(m_dLumens,'g',0);
    }


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

   bool FixtureData::isNotValid(double dNumToTest)
    {
        if (dNumToTest > 1000000|| dNumToTest <= 0)
            return true;
        return false;
    }

    FixtureData& FixtureData::operator = (const FixtureData &cSource)
    {
        m_FixtureName = cSource.m_FixtureName;
        m_dCandela = cSource.m_dCandela;
        m_dLumens = cSource.m_dLumens;
        m_dDistanceMeters = cSource.m_dDistanceMeters;
        m_dLux = cSource.m_dLux;
        m_dDistanceFeet = cSource.m_dDistanceFeet;
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




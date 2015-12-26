#include "mattcalculations.h"
#include "constsants.h"
#include <qstring.h>
#include <qlocale.h>



bool doubleIsEqual (double x, double y, unsigned int nNumberOfDecimalPlaces)
{
    int nMultiplyer = 1;
    for(int iii = 1; iii <= nNumberOfDecimalPlaces; iii++)
        nMultiplyer *= 10;
    return (static_cast<int>(x*nMultiplyer + 0.5) == static_cast<int>(y*nMultiplyer + 0.5));
}

double usDollarsStringToDouble(QString qstrDollars)
{
    bool ok;
    qstrDollars.remove('$').remove(',');
    double dValue = qstrDollars.toDouble(&ok);
    if (ok)
        return dValue;
    else
        return 0;
}

QString doubleToCurrency (double dInput, unsigned int nCurrency = US_DOLLARS)
{
    QString qstrCurrency;
    switch (nCurrency)
    {
        case US_DOLLARS:     {qstrCurrency = "$ "; break;}
    }

    qstrCurrency.append(QLocale (QLocale::English).toString(dInput));
    return qstrCurrency;
}

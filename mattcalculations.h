#ifndef MATTCALCULATIONS
#define MATTCALCULATIONS

#ifndef QSTRING_H
#include <qstring.h>
#endif

enum curency{
    US_DOLLARS = 0,
};

bool doubleIsEqual (double x, double y, unsigned int nNumberOfDecimalPlaces);

double usDollarsStringToDouble(QString qstrDollars);
QString doubleToCurrency (double dInput, unsigned int nCurrency);

#endif // MATTCALCULATIONS


#include "commonconversions.h"

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "FixtureData.h"
#include "fixtruecalculations.h"
#include <iomanip>
#include <fstream>

#include <QDialog>

double convertQStringToDouble (QString qstrQString)
{
    double dDouble=0;
    std::stringstream ssTemp;
    ssTemp.flush();
    std::string strString = qstrQString.toStdString();
    ssTemp << strString;
    ssTemp >> dDouble;
    return dDouble;

}

double convertStdStringToDouble(std::string input)
{
    std::stringstream ssTemp;
    double dDouble = 0;
    int nNumLength = input.length();

    for(int iii = 0, nNumOfDecPnts = 0; iii < nNumLength; iii++)
    {
        if (CharIsNum(input[iii])||input[iii]== '.' )
        {
            if (input[iii] == '.')
            {
                nNumOfDecPnts++;
                if (nNumOfDecPnts > 1)
                    return 0;
            }
            ssTemp << input[iii];
        }
        else if (!(input[iii] == ','))
            return 0;
    }
    ssTemp >> dDouble;
    return dDouble;
}



bool CharIsNum (char input)
{
    switch (input)
    {
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
        return true;
    }
    return false;
}


#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "FixtureData.h"
#include "fixtruecalculations.h"
#include <iomanip>
#include <fstream>

#define MAX_NUM_FIXTURES 10

void OpenSavedData(AllData &cData)
{
    using namespace std;

    ifstream inf("Fixture Data.csv");

    if(!inf)
    {
        cerr << "Warning! Could not open file (Fixture Data.csv) " << endl;
        exit (1);
    }

    //work to be done here

}


void SaveToFile(AllData &cData)
{
    std::ofstream outf("Fixture Data.csv");
    outf << cData;

    outf << "Fixture name,Candela,Distance in Meters,Lux,Distance in feet,Footcandles,Field angle,Field diameter in meters,Field Diameter in feet" << std::endl;

    for (unsigned int iii = 1; iii <= cData.nNumberOfFixtures; iii++)
        outf << cData.Fixture[iii];
}





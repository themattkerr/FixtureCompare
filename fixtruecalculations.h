#ifndef FIXTRUECALCULATIONS_H
#define FIXTRUECALCULATIONS_H


#define PI 3.14159265
#define LuxToFootcandleRatio 0.09290304
#define EmperialToMetricCoefficient 10.7631
#define FeetPerMeter 3.28



enum MeasurmentSystem
{
    EMPERIAL = 0,
    METRIC = 1,
};

enum ProgramFlow
{
    STOP = 0,
    KEEP_GOING = 1,
    SINGLE_FIXTURE = 0,
    ALL_FIXTURES = 1,
};






// forward declarations
class AllData;
void clearScreen();
//bool EditFixturesMenu(AllData &cData);
//int GetNumberOfFixtures(AllData &cData);
void SaveToFile(AllData &cData);
//void printFixtureInfo(AllData &cData, int nFixtureNumber);
//void printAllFixtures(AllData &cData);
//void PrintLine();
//bool AddEditQuit(AllData &cData);
bool editSingleFixture(AllData &cData);
void MakeEditsTofixture (AllData &cData);
bool EditFixturesMenu(AllData &cData, unsigned int nLowRange, unsigned int nHighRange);

#endif // FIXTRUECALCULATIONS_H


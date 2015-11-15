#include "mainwindow.h"
#include <QApplication>



#include <iostream>
#include <cmath>
#include <string>
#include "fixtruecalculations.h"
#include "FixtureData.h"
#include <fstream>


int main(int argc, char *argv[])
{
    using namespace std;
    bool bContinue = KEEP_GOING;
    AllData cData;


    GetNumberOfFixtures(cData);
    while (bContinue)
    { bContinue = AddEditQuit(cData);}

    clearScreen();
    cout << "You have decided to leave the program" << endl;
    SaveToFile(cData);


    return 0;
}

/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
*/

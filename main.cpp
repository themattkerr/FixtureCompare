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
    QApplication a(argc, argv);
    AllData cData;
    MainWindow w;
    w.show();

    return a.exec();
}


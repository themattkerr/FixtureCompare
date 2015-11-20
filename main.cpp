#include "mainwindow.h"
#include <QApplication>

#include "FixtureData.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AllData cData;
    MainWindow w;
    w.show();

    return a.exec();
}


#include "mainwindow.h"
#include <QApplication>
#include <QDir>

//#include "FixtureData.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir x;
    if (!x.exists("Files"))
        x.mkdir("Files");

    MainWindow w;
    w.show();

    return a.exec();
}


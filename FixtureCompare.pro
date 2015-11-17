#-------------------------------------------------
#
# Project created by QtCreator 2015-11-15T06:49:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FixtureCompare
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fixturecalculations.cpp \
    fixturedata.cpp \
    startupdialog.cpp \
    fixtureeditdialog.cpp \
    commonconversions.cpp

HEADERS  += mainwindow.h \
    fixtruecalculations.h \
    fixturedata.h \
    constsants.h \
    startupdialog.h \
    fixtureeditdialog.h \
    commonconversions.h

FORMS    += mainwindow.ui \
    startupdialog.ui \
    fixtureeditdialog.ui

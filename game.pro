#-------------------------------------------------
#
# Project created by QtCreator 2014-03-27T01:35:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamestartwidget.cpp \
    gameplaywidget.cpp \
    gamesettingwidget.cpp

HEADERS  += mainwindow.h \
    gamestartwidget.h \
    gameplaywidget.h \
    gamesettingwidget.h

FORMS    += mainwindow.ui \
    gamestartwidget.ui \
    gameplaywidget.ui \
    gamesettingwidget.ui

OTHER_FILES +=

RESOURCES += \
    R.qrc

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
    gamesettingwidget.cpp \
    barleybreak.cpp \
    gametileswidget.cpp \
    GlobalSettings.cpp \
    tile.cpp \
    TilesGame.cpp

HEADERS  += mainwindow.h \
    gamestartwidget.h \
    gameplaywidget.h \
    gamesettingwidget.h \
    barleybreak.h \
    gametileswidget.h \
    GlobalSettings.h \
    tile.h \
    TilesGame.h

FORMS    += mainwindow.ui \
    gamestartwidget.ui \
    gameplaywidget.ui \
    gamesettingwidget.ui \
    gametileswidget.ui

OTHER_FILES += \
    qss/style.css \
    qss/img/restartbtnpressed.png \
    qss/img/restartbtn.png \
    qss/img/radio_unchecked.png \
    qss/img/radio_checked.png \
    qss/img/pausebtnpressed.png \
    qss/img/pausebtn.png \
    qss/img/exitbtnpressed.png \
    qss/img/exitbtn.png \
    qss/img/bigbtnpressed.png \
    qss/img/bigbtn.png \
    qss/img/bgplay.png \
    qss/img/bg.png

RESOURCES += \
    R.qrc

QMAKE_CXXFLAGS += -std=c++11

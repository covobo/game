#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets>
#include <QWidget>
#include "gametileswidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stateOfGame(new QStateMachine),
    winner(new QState),
    start(new QState),
    game(new QState),
    setting(new QState)

{
    ui->setupUi(this);
    setDefaultStyle();
    initAllStateAndStartMachine();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/* init all state for navigating stacked widget */
void MainWindow::initAllStateAndStartMachine(){
    winner->assignProperty(ui->stackedWidget, "currentIndex", WINNER_SCREEN_INDEX);
    winner->addTransition(ui->gameWinner->findChild<QPushButton *>(QString("newGameBtn")), SIGNAL(clicked()), game);
    winner->addTransition(ui->gameWinner->findChild<QPushButton *>(QString("exitGameBtn")), SIGNAL(clicked()), start);
    connect(winner, SIGNAL(propertiesAssigned()), ui->gameWinner, SLOT(setTime()));

    // GameSettingWidget
    setting->assignProperty(ui->stackedWidget, "currentIndex", SETTING_SCREEN_INDEX);
    setting->addTransition(ui->gameSetting->findChild<QPushButton *>(QString("goStartScreenBtn")), SIGNAL(clicked()), start);

    // GameStartWidget
    start->assignProperty(ui->stackedWidget, "currentIndex", START_SCREEN_INDEX);
    start->addTransition(ui->gameStart->findChild<QPushButton *>(QString("newGameBtn")), SIGNAL(clicked()), game);
    start->addTransition(ui->gameStart->findChild<QPushButton *>(QString("settingBtn")), SIGNAL(clicked()), setting);


    // GamePlayWidget
    game->assignProperty(ui->stackedWidget, "currentIndex", GAME_SCREEN_INDEX);
    game->addTransition(ui->gamePlay->findChild<QPushButton *>(QString("exitGameBtn")), SIGNAL(clicked()), start);
    game->addTransition(ui->gamePlay->findChild<GameTilesWidget *>(QString("gameTiles")), SIGNAL(iAmWinner()), winner);

    connect(game, SIGNAL(propertiesAssigned()), ui->gamePlay, SLOT(restartTimer()));
    connect(game, SIGNAL(propertiesAssigned()), ui->gamePlay, SLOT(restartGame()));

    stateOfGame->addState(winner);
    stateOfGame->addState(start);
    stateOfGame->addState(game);
    stateOfGame->addState(setting);

    stateOfGame->setInitialState(winner);
    stateOfGame->start();
}
void MainWindow::setDefaultStyle(){
    QFile f(QString(DEFAULT_STYLE_NAME));
    f.open(QFile::ReadOnly);
    QString stylSheet = QLatin1String(f.readAll());
    f.close();
    dynamic_cast<QApplication*>(QCoreApplication::instance())->setStyleSheet(stylSheet);
}

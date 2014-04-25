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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    stateOfGame(new QStateMachine),
    start(new QState),
    game(new QState),
    setting(new QState),
    youAreWinner(new QState)
{
    ui->setupUi(this);

    initAllStateAndStartMachine();
    setDefaultStyle();
}

MainWindow::~MainWindow()
{
    delete ui;
}
/* init all state for navigating stacked widget */
void MainWindow::initAllStateAndStartMachine(){
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


    stateOfGame->addState(start);
    stateOfGame->addState(game);
    stateOfGame->addState(setting);

    stateOfGame->setInitialState(start);
    stateOfGame->start();
}
void MainWindow::setDefaultStyle(){
    QFile f(QString("://qss/style.css"));
    f.open(QFile::ReadOnly);
    QString stylSheet = QLatin1String(f.readAll());
    f.close();
    dynamic_cast<QApplication*>(QCoreApplication::instance())->
            setStyleSheet(stylSheet);
}

#include "gameplaywidget.h"
#include "ui_gameplaywidget.h"
#include "QPushButton"
#include "QString"
#include <QSizePolicy>
#include <QCursor>
#include <QTimer>
#include "barleybreak.h"

GamePlayWidget::GamePlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePlayWidget),
    gameLogic(new BarleyBreak),
    timer(new QTimer(this))
{
    ui->setupUi(this);
    timer->setInterval(timerspeed);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->pauseGameBtn, SIGNAL(clicked()), this, SLOT(triggerPauseAndPlayGame()));
    connect(ui->restartGameBtn, SIGNAL(clicked()), this, SLOT(restartTimerAndEmitSignal()));
}

GamePlayWidget::~GamePlayWidget()
{
    delete ui;
}

void GamePlayWidget::updateTimer()
{
    setTime(milisecondsOfGame+timerspeed);
}

void GamePlayWidget::restartTimer()
{
    timer->stop();
    timer->start();
    milisecondsOfGame = -timerspeed;
}

void GamePlayWidget::triggerPauseAndPlayGame()
{
    if(ui->gameTiles->isHidden()){
        ui->gameTiles->show();
        timer->start();
        ui->pauseGameBtn->setText(QString("Пауза"));
    } else {
        timer->stop();
        ui->gameTiles->hide();
        ui->pauseGameBtn->setText(QString("Продолжить"));
    }

}

void GamePlayWidget::restartTimerAndEmitSignal()
{
    restartTimer();
    emit restartGame();
}

void GamePlayWidget::setTime(int second)
{
    milisecondsOfGame = second;
    int minuts  = (milisecondsOfGame / 1000) / 60;
    int seconds = (milisecondsOfGame / 1000) % 60;
    QString string("");
    string.append(QString::number(minuts));
    string.append("м:");
    string.append(QString::number(seconds));
    string.append("с");
    ui->timerGame->setText(string);
}

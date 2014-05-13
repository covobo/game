#include "gameplaywidget.h"
#include "ui_gameplaywidget.h"
#include "QGridLayout"
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
    timer->setInterval(timerspeed); // 1s
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    connect(ui->pauseGameBtn, SIGNAL(clicked()), this, SLOT(triggerPauseAndPlayGame()));
    connect(ui->restartGameBtn, SIGNAL(clicked()), this, SLOT(restartGame()));
    game();
}

GamePlayWidget::~GamePlayWidget()
{
    delete ui;
}

void GamePlayWidget::updateTimer()
{
    setTime(secondsOfGame+timerspeed);
}

void GamePlayWidget::restartTimer()
{
    timer->stop();
    timer->start();
    secondsOfGame = -timerspeed;
}

void GamePlayWidget::triggerPauseAndPlayGame()
{
    if(ui->gridWidget->isHidden()){
        ui->gridWidget->show();
        timer->start();
        ui->pauseGameBtn->setText(QString("Пауза"));
    } else {
        timer->stop();
        ui->gridWidget->hide();
        ui->pauseGameBtn->setText(QString("Продолжить"));
    }

}

void GamePlayWidget::restartGame()
{
    restartTimer();
    game();
}

void GamePlayWidget::setTime(int second)
{
    secondsOfGame = second;
    int minuts  = (secondsOfGame / 1000) / 60;
    int seconds = (secondsOfGame / 1000) % 60;
    QString string("");
    string.append(QString::number(minuts));
    string.append("м:");
    string.append(QString::number(seconds));
    string.append("с");
    ui->timerGame->setText(string);
}

void GamePlayWidget::game()
{
    int size = 4;
    int sizeBtn = 320/size;
    for(int i = 1; i <= size; i++){
        for(int y = 1; y <= size; y++){
            QPushButton* btn = new QPushButton(this);
            btn->setProperty("isCell", "true"); // for QSS
            btn->setText(QString::number(i*size-size+y));
            btn->setCursor(Qt::PointingHandCursor);
            btn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            ui->gridLayout->addWidget(dynamic_cast<QWidget*>(btn), i-1, y-1);
        }
    }

}

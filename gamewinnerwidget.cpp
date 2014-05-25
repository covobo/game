#include "gamewinnerwidget.h"
#include "ui_gamewinnerwidget.h"
#include "GlobalSettings.h"

GameWinnerWidget::GameWinnerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWinnerWidget)
{
    ui->setupUi(this);
}

GameWinnerWidget::~GameWinnerWidget()
{
    delete ui;
}

void GameWinnerWidget::setTime()
{
    GlobalSettings* setting = GlobalSettings::Instance();
    ui->time->setText(QString("Ваше время - ").append(setting->getLastTimePlay()));
}

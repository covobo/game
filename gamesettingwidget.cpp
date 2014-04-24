#include "gamesettingwidget.h"
#include "ui_gamesettingwidget.h"

GameSettingWidget::GameSettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameSettingWidget)
{
    ui->setupUi(this);
}

GameSettingWidget::~GameSettingWidget()
{
    delete ui;
}

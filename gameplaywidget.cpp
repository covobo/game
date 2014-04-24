#include "gameplaywidget.h"
#include "ui_gameplaywidget.h"

GamePlayWidget::GamePlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePlayWidget)
{
    ui->setupUi(this);
}

GamePlayWidget::~GamePlayWidget()
{
    delete ui;
}

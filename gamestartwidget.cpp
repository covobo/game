#include "gamestartwidget.h"
#include "ui_gamestartwidget.h"

GameStartWidget::GameStartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStartWidget)
{
    ui->setupUi(this);
}

GameStartWidget::~GameStartWidget()
{
    delete ui;
}

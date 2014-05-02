#include "gameplaywidget.h"
#include "ui_gameplaywidget.h"
#include "QGridLayout"
#include "QPushButton"
#include "QString"
#include <QSizePolicy>
#include <QCursor>
#include "barleybreak.h"

GamePlayWidget::GamePlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePlayWidget),
    gameLogic(new BarleyBreak)
{
    ui->setupUi(this);    


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

GamePlayWidget::~GamePlayWidget()
{
    delete ui;
}

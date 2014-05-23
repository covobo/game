#include "gametileswidget.h"
#include "ui_gametileswidget.h"
#include <QPushButton>
#include <QGridLayout>
#include "GlobalSettings.h"
#include <QLayoutItem>
#include <QDebug>

GameTilesWidget::GameTilesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTilesWidget)
{
    ui->setupUi(this);
    GlobalSettings* settings = GlobalSettings::Instance();
    connect(settings, SIGNAL(gameBoardSizeValueChanged(int)), this, SLOT(remakeBoardAndFill(int)));
    createAndfillBoard(settings->getGameBoardSize());
}

GameTilesWidget::~GameTilesWidget()
{
    delete ui;
}
void GameTilesWidget::createAndfillBoard(int size)
{
    for(int i = 1; i <= size; i++){
        for(int y = 1; y <= size; y++){
            if(!(i == size && i == y)){ // left bottom item is empty
                QPushButton* btn = new QPushButton(this);
                btn->setProperty("isCell", "true"); // for QSS
                btn->setText(QString::number(i*size-size+y));
                btn->setCursor(Qt::PointingHandCursor);
                btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                ui->gridLayout->addWidget(dynamic_cast<QWidget*>(btn), i-1, y-1);
            }
        }
    }
}

void GameTilesWidget::remakeBoardAndFill(int size)
{
    qDebug() << QString("remake size: ").append(QString::number(size));
    removeAllChilds(ui->gridLayout);
    createAndfillBoard(size);
}


void GameTilesWidget::removeAllChilds(QGridLayout *layout) {
    QLayoutItem *child;
    QWidget *w;
    while((child = layout->takeAt(0)) != 0){
        w = child->widget();
        layout->removeItem(child);
        delete child;
        delete w;
    }
}


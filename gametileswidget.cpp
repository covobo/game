#include "gametileswidget.h"
#include "ui_gametileswidget.h"
#include <QPushButton>
#include <QGridLayout>
#include "GlobalSettings.h"
#include <QLayoutItem>
#include <QDebug>
#include "TilesGame.h"
#include <QSignalMapper>

GameTilesWidget::GameTilesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameTilesWidget)
{
    ui->setupUi(this);
    settings = GlobalSettings::Instance();
}
// получили сигнал, что изменилось состояние
// получили вектор плиток, собираем поле
void GameTilesWidget::remakeBoard(QVector<Tile*>* tiles){
    removeAllChilds(ui->gridLayout);
    Tile* element;
    for(int x = 0; x < tiles->size(); x++){
        element = tiles->at(x);        
        QPushButton* btn = new QPushButton(this);
        btn->setProperty("isCell", "true"); // for QSS
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->gridLayout->addWidget(dynamic_cast<QWidget*>(btn), element->getY(), element->getX());
        signalMapper->setMapping(btn, dynamic_cast<QObject*>(element));
        if(!element->isEmpty()){
            btn->setText(QString::number(element->getValue()));
            connect(btn, SIGNAL(pressed()), signalMapper, SLOT(map()));
            btn->setCursor(Qt::PointingHandCursor);
        } else {
             btn->setProperty("isEmptyCell", "true"); // for QSS
        }
    }
}
// на плитку кликнули - дёргаем функцию логики
// если что-то изменилось, мы получим об этом сигнал
void GameTilesWidget::tileWasClicked(QObject* obj)
{
    Tile* tile = dynamic_cast<Tile*>(obj);
    if(gameLogic != NULL && tile != NULL)
        gameLogic->move(tile);
}

void GameTilesWidget::winner()
{
    qDebug() << "YOU WON!";
    emit iAmWinner();
}
// удаляем все конекты, пересоздаём логику и переписываем коннекты
void GameTilesWidget::createLogicAndBoard()
{
    int size = settings->getGameBoardSize();
    removeAllChilds(ui->gridLayout);
    disconnect(this, SLOT(remakeBoard(QVector<Tile*>*)));
    disconnect(this, SLOT(winner()));
    disconnect(this, SLOT(tileWasClicked(QObject* obj)));
    delete gameLogic;
    delete signalMapper;
    gameLogic = settings->getGameLogicObject(size);
    signalMapper = new QSignalMapper(this);
    connect(gameLogic, SIGNAL(gameBoardChanged(QVector<Tile*>*)),this,SLOT(remakeBoard(QVector<Tile*>*)));
    connect(signalMapper, SIGNAL(mapped(QObject*)), this, SLOT(tileWasClicked(QObject*)));
    connect(gameLogic, SIGNAL(winner()), this, SLOT(winner()));
    gameLogic->start();
}
// фуункция хелпер для отчитки QGridLayout
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
GameTilesWidget::~GameTilesWidget()
{
    removeAllChilds(ui->gridLayout);
    disconnect(this, SLOT(remakeBoard(QVector<Tile*>*)));
    disconnect(this, SLOT(winner()));
    disconnect(this, SLOT(tileWasClicked(QObject* obj)));
    delete ui;
    delete gameLogic;
}


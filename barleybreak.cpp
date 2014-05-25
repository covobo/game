#include "barleybreak.h"
#include "TilesGame.h"
#include "tile.h"
#include <QVector>
#include <QString>
#include <QDebug>
#include <QTime>
#include <QtGlobal>

BarleyBreak::BarleyBreak(int gameBoardSize) :
    TilesGame(gameBoardSize)
{
    // делаем из последней плитки - пустую плитку
    tiles->remove(this->gameBoardSize*this->gameBoardSize-1);
    tiles->prepend(new Tile(this->gameBoardSize-1, this->gameBoardSize-1, this->gameBoardSize*this->gameBoardSize, true));
    shuffle();
}
// пустая клетка должна быть в радиусе 1
// но не по диагонали.
// и не на противоположных сторонах
bool BarleyBreak::moveTile(Tile* tile)
{
    Tile* emptyTile = findEmptyTile();
    Tile* moviableTile = findTile(tile->getX(), tile->getY());
    if(emptyTile != NULL && moviableTile != NULL){
        int difY = qAbs(emptyTile->getY()-moviableTile->getY());
        int difX = qAbs(emptyTile->getX()-moviableTile->getX());

        if((difY == 1 || difX == 1) && difX != difY && difX < 2 && difY < 2){
            swap(moviableTile->getX(),
                 moviableTile->getY(),
                 emptyTile->getX(),
                 emptyTile->getY());
            return true;
        }

    }
    return false;
}
// если координаты ячейки совпадают с значением
// и так для всех ячекк - значит ячейки выстроены правильно и игра завершена
bool BarleyBreak::gameEnded()
{
    Tile* element;
    int value;
    for(int i = 1; i <= this->tiles->count(); i++){
        element = this->tiles->at(i-1);
        value = element->getY()*this->gameBoardSize+element->getX();

        if(element->getValue()-1 != value ){
            return false;
        }
    }
    return true;
}
// имитируем случайные клики, чтобы раскидать ячейки
// нельзя сортировать рандомно, необходимо именно имитировать
// т.к. ровно половину возможных состояний невозможно собрать
void BarleyBreak::shuffle()
{
    //return;
    int countStep = this->gameBoardSize*60; // 60 рандомное число
                                             // количество кликов
    int direction = 0;
    Tile* element;
    int x = 0;
    int y = 0;
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
    for(int i = 0; i < countStep; i++){
        direction = qrand() % 4; /* rand int from 0 to 3 */
        element = findEmptyTile();
        x = element->getX();
        y = element->getY();
        switch(direction){
            case 0: // up
                swap(x, y, x, y-1);
            break;
            case 1: // down
                swap(x, y, x, y+1);
            break;
            case 2: // left
                swap(x, y, x-1, y);
            break;
            case 3:
            default: // right
               swap(x, y, x+1, y);
            break;
        }
    }
    // если нам сильно повезло, и мы собрали выиграшную комбинацию пятнашек
    // раскидываем ячейки ещё раз
    if(gameEnded())
        shuffle();
}
// поменять местами 2 ячейки
void BarleyBreak::swap(int x_from,int y_from,int x_to,int y_to)
{
    if(y_to < 0 || y_to > this->gameBoardSize-1)
        return;
    if(x_to < 0 || x_to > this->gameBoardSize-1)
        return;
    Tile* from = findTile(x_from, y_from);
    Tile* to = findTile(x_to, y_to);
    if(from == NULL || to == NULL)
        return;
    to->setX(x_from);
    to->setY(y_from);
    from->setX(x_to);
    from->setY(y_to);
}

Tile *BarleyBreak::findEmptyTile()
{
    Tile* result;
    for(int i = 0; i < this->tiles->size(); i++){
        result = this->tiles->at(i);
        if(result->isEmpty())
            return result;
    }
    return NULL;
}


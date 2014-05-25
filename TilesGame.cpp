#include "TilesGame.h"
#include <QVector>
#include "tile.h"
#include <QDebug>

TilesGame::TilesGame(int gameBoardSize)
{
    this->gameBoardSize = gameBoardSize;
    this->tiles = new QVector<Tile*>();
    int value = 0;
    for(int y = this->gameBoardSize; y > 0 ; y--){
        for(int x = this->gameBoardSize; x > 0; x--){
            value = y*this->gameBoardSize-(this->gameBoardSize-x);
            tiles->prepend(new Tile(x-1,y-1, value, false));
        }
    }
}
void TilesGame::move(Tile* tile)
{
    if(moveTile(tile)){
        emit gameBoardChanged(tiles);
    }
    if(gameEnded()){
        emit winner();
    }
}

void TilesGame::start()
{
    emit gameBoardChanged(this->tiles);
}

TilesGame::~TilesGame()
{
    delete tiles;
}


Tile *TilesGame::findTile(int x, int y)
{
    Tile* element;
    for(int i = 0; i < this->tiles->size(); i++){
        element = this->tiles->at(i);
        if(element->getX() == x && element->getY() == y)
            return element;
    }
    return NULL;
}

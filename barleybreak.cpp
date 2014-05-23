#include "barleybreak.h"

BarleyBreak::BarleyBreak(int size)
{
    if(size % 2 != 0){
        size += 1;
    }
    this->gameSize = size;
    //tiles = new QVector<Tile*>(this->gameSize);
    createTiles();
    shuffle();

}

void BarleyBreak::shuffle()
{

}
void BarleyBreak::createTiles(){
    for(int i = 0; i < this->gameSize; i++){
       // tiles->push_back(new Tile(i));
    }
}

#include "tile.h"

Tile::Tile(int x, int y, int value, bool empty)
{
    this->x = x;
    this->y = y;
    this->value = value;
    this->empty = empty;
}
int Tile::getValue(){
    return value;
}
int Tile::getX(){
    return x;
}
int Tile::getY(){
    return y;
}
bool Tile::isEmpty(){
    return this->empty;
}

void Tile::setX(int x)
{
    this->x = x;
}

void Tile::setY(int y)
{
    this->y = y;
}

void Tile::setValue(int value)
{
    this->value = value;
}

void Tile::setEmpty(bool empty)
{
    this->empty = empty;
}

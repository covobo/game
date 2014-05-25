#ifndef TILE_H
#define TILE_H
#include <QObject>

class Tile : public QObject
{
public:
    Tile(int x, int y, int value, bool empty);
    int getX();
    int getY();
    int getValue();
    bool isEmpty();
    void setX(int x);
    void setY(int y);
    void setValue(int value);
    void setEmpty(bool empty);

private:
    int x;
    int y;
    int value;
    bool empty;
};

#endif // TILE_H

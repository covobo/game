#ifndef BARLEYBREAK_H
#define BARLEYBREAK_H

#include <QVector>
#include <QList>
#include <tile.h>
#include <TilesGame.h>

class BarleyBreak : public TilesGame
{
    Q_OBJECT
public:
    BarleyBreak(int size = 4);
private:
    virtual bool moveTile(Tile* tile);
    virtual bool gameEnded();
    void shuffle();
    void swap(int x_from,int y_from,int x_to, int y_to);
    Tile* findEmptyTile();
};

#endif // BARLEYBREAK_H

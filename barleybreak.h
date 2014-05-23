#ifndef BARLEYBREAK_H
#define BARLEYBREAK_H

#include <QVector>
#include <QList>
class BarleyBreak
{
public:
    BarleyBreak(int size = 16);
private:
    void shuffle();
    void createTiles();

private:
    int gameSize;  // must be even
};

#endif // BARLEYBREAK_H

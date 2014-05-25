#include <QVector>
#include <tile.h>
#include <QWidget>

#ifndef ABSTRACTTILESGAME_H
#define ABSTRACTTILESGAME_H
/*
 * Абстрактная игра с плитками
 * должна знать о размерах игрового поля
 * должна уметь двигать плитку
 * должна уметь создавать сигнал, который возвращает массив плиток
 * т.е. состояние игрового поля
 * должна создавать сигнал, если игра выиграна
*/
class TilesGame : public QWidget
{
       Q_OBJECT
public:
    TilesGame(int gameBoardSize);
    ~TilesGame();
    void move(Tile* tile);
    void start();
signals:
    void gameBoardChanged(QVector<Tile*>* tiles);
    void winner();
protected:    
    virtual bool moveTile(Tile* tile) = 0;
    virtual bool gameEnded() = 0;
    QVector<Tile*>* tiles;
    int gameBoardSize;
    Tile* findTile(int x, int y);

};

#endif // ABSTRACTTILESGAME_H

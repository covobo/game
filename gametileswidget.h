#ifndef GAMETILESWIDGET_H
#define GAMETILESWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QGridLayout>
#include "GlobalSettings.h"
#include <QVector>
#include "tile.h"
#include "TilesGame.h"
#include <QSignalMapper>

namespace Ui {
class GameTilesWidget;
}

class GameTilesWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameTilesWidget(QWidget *parent = 0);
    ~GameTilesWidget();
public slots:
    void createLogicAndBoard(); // создаем локику, игровое поле
    void remakeBoard(QVector<Tile*>* tiles); // пересобираем игровое поле
    void tileWasClicked(QObject* tile); // при клике на плитку, дёргаем методы логики
    void winner(); // слот для получения события выигрыга от логики
signals:
    void iAmWinner(); // этот сигнал создаем сами
private:
    Ui::GameTilesWidget *ui;
    void createAndfillBoard(int size);
    void removeAllChilds(QGridLayout *layout);
    TilesGame* gameLogic;
    GlobalSettings* settings;
    QSignalMapper* signalMapper;
};

#endif // GAMETILESWIDGET_H

#ifndef GAMEPLAYWIDGET_H
#define GAMEPLAYWIDGET_H

#include <QWidget>
#include "barleybreak.h"

namespace Ui {
class GamePlayWidget;
}

class GamePlayWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GamePlayWidget(QWidget *parent = 0);
    ~GamePlayWidget();
    
private:
    Ui::GamePlayWidget *ui;
    BarleyBreak* gameLogic;
};

#endif // GAMEPLAYWIDGET_H

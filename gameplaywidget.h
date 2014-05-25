#ifndef GAMEPLAYWIDGET_H
#define GAMEPLAYWIDGET_H

#include <QWidget>
#include <QTimer>
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
    int milisecondsOfGame = 0;

public slots:
    void updateTimer();
    void restartTimer();
    void triggerPauseAndPlayGame();
    void restartGame();
    void showTimer();
    void hideTimer();
    void saveTime();

private:
    Ui::GamePlayWidget *ui;
     void setTime(int);
    QTimer* timer;
    int timerspeed = 100; // 0.1s

};

#endif // GAMEPLAYWIDGET_H

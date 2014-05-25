#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define START_SCREEN_INDEX 0
#define GAME_SCREEN_INDEX 1
#define SETTING_SCREEN_INDEX 2
#define WINNER_SCREEN_INDEX 3
#define DEFAULT_STYLE_NAME "://qss/default/default.qss"

#include <QMainWindow>
#include <QStateMachine>
#include <QState>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QStateMachine *stateOfGame;
    QState *start;
    QState *game;
    QState *setting;
    QState *youAreWinner;
    void initAllStateAndStartMachine();
    void setDefaultStyle();
};

#endif // MAINWINDOW_H

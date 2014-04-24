#ifndef GAMESETTINGWIDGET_H
#define GAMESETTINGWIDGET_H

#include <QWidget>

namespace Ui {
class GameSettingWidget;
}

class GameSettingWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameSettingWidget(QWidget *parent = 0);
    ~GameSettingWidget();
    
private:
    Ui::GameSettingWidget *ui;
};

#endif // GAMESETTINGWIDGET_H

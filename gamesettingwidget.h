#ifndef GAMESETTINGWIDGET_H
#define GAMESETTINGWIDGET_H

#include <QWidget>
#define DEFAULT_STYLE_PATH ":/qss"
namespace Ui {
class GameSettingWidget;
}

class GameSettingWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameSettingWidget(QWidget *parent = 0);
    ~GameSettingWidget();
    
private slots:
    void on_chooseStyleBox_currentIndexChanged(int index);

private:
    Ui::GameSettingWidget *ui;
};

#endif // GAMESETTINGWIDGET_H

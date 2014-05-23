#ifndef GAMESETTINGWIDGET_H
#define GAMESETTINGWIDGET_H
#include "GlobalSettings.h"
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

    void on_dificulRadioBtn_clicked();

    void on_dificulRadioBtn_2_clicked();

private:
    Ui::GameSettingWidget *ui;
    GlobalSettings* globalSettings;
};

#endif // GAMESETTINGWIDGET_H

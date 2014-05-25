#ifndef GAMEWINNERWIDGET_H
#define GAMEWINNERWIDGET_H

#include <QWidget>

namespace Ui {
class GameWinnerWidget;
}

class GameWinnerWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWinnerWidget(QWidget *parent = 0);
    ~GameWinnerWidget();
public slots:
    void setTime(); // забирает из глобальных настроек форматированное в строчку время

private:
    Ui::GameWinnerWidget *ui;
};

#endif // GAMEWINNERWIDGET_H

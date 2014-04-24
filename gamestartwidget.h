#ifndef GAMESTARTWIDGET_H
#define GAMESTARTWIDGET_H

#include <QWidget>

namespace Ui {
class GameStartWidget;
}

class GameStartWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameStartWidget(QWidget *parent = 0);
    ~GameStartWidget();

private:
    Ui::GameStartWidget *ui;
};

#endif // GAMESTARTWIDGET_H

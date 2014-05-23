#ifndef GAMETILESWIDGET_H
#define GAMETILESWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QGridLayout>

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
    void remakeBoardAndFill(int size);
private:
    Ui::GameTilesWidget *ui;
    void createAndfillBoard(int size);
    void removeAllChilds(QGridLayout *layout);
};

#endif // GAMETILESWIDGET_H

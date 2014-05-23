#ifndef GLOBALSETTINGS_H
#define GLOBALSETTINGS_H
#define DEFAULT_GAME_BOARD_SIZE 4
#include <QObject>

class GlobalSettings : public QObject
{
    Q_OBJECT
public:
    void setGameBoardSize(int newValue);
    int getGameBoardSize();
    static GlobalSettings* Instance();

private:
    int GAME_BOARD_SIZE;
    GlobalSettings();
    GlobalSettings& operator=(GlobalSettings const&);
    static GlobalSettings* GlobalSettingsInstance;

signals:
    void gameBoardSizeValueChanged(int newValue);
};

#endif // GLOBALSETTINGS_H

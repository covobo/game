#include "GlobalSettings.h"
#include "barleybreak.h"
#include "TilesGame.h"

GlobalSettings* GlobalSettings::GlobalSettingsInstance = NULL;
GlobalSettings::GlobalSettings() :
    QObject()
{
    GAME_BOARD_SIZE = DEFAULT_GAME_BOARD_SIZE;
}

GlobalSettings* GlobalSettings::Instance()
{
    if(!GlobalSettingsInstance)
        GlobalSettingsInstance = new GlobalSettings();
    return GlobalSettingsInstance;
}

TilesGame* GlobalSettings::getGameLogicObject(int gameBoardSize)
{
    return dynamic_cast<TilesGame*>(new BarleyBreak(gameBoardSize));
}

void GlobalSettings::setTimePlay(QString stringTime)
{
    timeplay = stringTime;
}

void GlobalSettings::setGameBoardSize(int newValue)
{
    if(GAME_BOARD_SIZE != newValue){
        GAME_BOARD_SIZE = newValue;
        emit gameBoardSizeValueChanged();
    }
}

int GlobalSettings::getGameBoardSize()
{
    return GAME_BOARD_SIZE;
}


QString GlobalSettings::getLastTimePlay()
{
    return timeplay;
}

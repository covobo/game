#include "GlobalSettings.h"

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

void GlobalSettings::setGameBoardSize(int newValue)
{
    if(GAME_BOARD_SIZE != newValue){
        GAME_BOARD_SIZE = newValue;
        emit gameBoardSizeValueChanged(newValue);
    }
}

int GlobalSettings::getGameBoardSize()
{
    return GAME_BOARD_SIZE;
}

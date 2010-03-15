#ifndef GAME_H
#define GAME_H

#include "QListWidgetItem"
#include "QDir"
#include "gameresults.h"

class Game
{
public:
    Game(QList<QListWidgetItem*>);

    void generateRandomCharacters();
    void getGameResults();

private:
    GameResults resultsWindow;
    QList<QListWidgetItem*> players;

    QDir playerDir;
};

#endif // GAME_H

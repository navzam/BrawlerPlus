#include "game.h"
#include "player.h"
#include "QMessageBox"
#include "characters.h"
#include <vector>

Game::Game(QList<QListWidgetItem*> players) : playerDir("./players")
{
    this->players = players;
}

void Game::generateRandomCharacters()
{
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok);
    QString message = "";

   for(int i = 0; i < players.count(); ++i)
   {
       Character* random = Characters::getInstance().getRandom();
       message += players.at(i)->text() + ": " + random->getName().c_str() + "\n";
   }

   msgBox.setText(message);
   msgBox.exec();
}

void Game::getGameResults()
{
    for(int i = 0; i < players.count(); ++i)
        resultsWindow.addPlayer(players.at(i)->text());
    
    if(resultsWindow.exec())
    {
        QString winner = resultsWindow.getWinner();
        vector<Player> loadedPlayers;
        for(int i = 0; i < players.count(); ++i)
        {
            Player player(players.at(i)->text().toStdString());
            player.load(String(String("players/") + player.name));
            loadedPlayers.push_back(player);
        }
        
        /* 1 vs 1 win/loss */
        if(loadedPlayers.size() == 2)
        {
            if(QString(loadedPlayers.at(0).name.c_str()) == winner)
            {
                loadedPlayers.at(0).wins[loadedPlayers.at(1).name].value += 1;
                loadedPlayers.at(1).losses[loadedPlayers.at(0).name].value += 1;
            }
            else
            {
                loadedPlayers.at(0).losses[loadedPlayers.at(1).name].value += 1;
                loadedPlayers.at(1).wins[loadedPlayers.at(0).name].value += 1;
            }
        }
        
        /* Group match win/loss */
        else
        {
            for(int j = 0; j < loadedPlayers.size(); ++j)
            {
                if(QString(loadedPlayers.at(j).name.c_str()) == winner)
                    loadedPlayers.at(j).groupWins++;
                else
                    loadedPlayers.at(j).groupLosses++;
            }
        }
        
        /* KOs and save */
        for(int k = 0; k < loadedPlayers.size(); ++k)
        {
            loadedPlayers.at(k).KOs += resultsWindow.getKOs(k + 1);
            loadedPlayers.at(k).save(playerDir.canonicalPath().toStdString() + "/" + loadedPlayers.at(k).name);
        }
    }
}

#include "game.h"
#include "player.h"
#include "QMessageBox"
#include "characters.h"

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

    resultsWindow.exec();

    QString winner = resultsWindow.getWinner();
    for(int j = 0; j < players.count(); ++j)
    {
        Player player(players.at(j)->text().toStdString());
        player.load(String(String("players/") + player.name));

        if(players.count() == 2)
        {
            if(QString(player.name.c_str()) == winner)
            {
                // INCREASE WINS AGAINST APPROPRIATE PLAYER
            }
            else
            {
                // INCREASE LOSSES AGAINST APPROPRIATE PLAYER
            }
        }

        else
        {
            if(QString(player.name.c_str()) == winner)
                player.groupWins++;
            else
                player.groupLosses++;
        }
        player.KOs += resultsWindow.getKOs(j + 1);

        player.save(playerDir.canonicalPath().toStdString() + "/" + player.name);
    }
}

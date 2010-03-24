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

    if(resultsWindow.exec())
    {
        QString winner = resultsWindow.getWinner();

        if(players.count() == 2)
        {
            Player playerOne(players.at(0)->text().toStdString());
            playerOne.load(String(String("players/") + playerOne.name));
            Player playerTwo(players.at(1)->text().toStdString());
            playerTwo.load(String(String("players/") + playerTwo.name));

            if(QString(playerOne.name.c_str()) == winner)
            {
                playerOne.wins[playerTwo.name].value += 1;
                playerTwo.losses[playerOne.name].value += 1;
            }
            else
            {
                playerOne.losses[playerTwo.name].value += 1;
                playerTwo.wins[playerOne.name].value += 1;
            }

            playerOne.KOs += resultsWindow.getKOs(1);
            playerTwo.KOs += resultsWindow.getKOs(2);

            playerOne.save(playerDir.canonicalPath().toStdString() + "/" + playerOne.name);
            playerTwo.save(playerDir.canonicalPath().toStdString() + "/" + playerTwo.name);
        }

        else
        {
            for(int j = 0; j < players.count(); ++j)
            {
                Player player(players.at(j)->text().toStdString());
                player.load(String(String("players/") + player.name));

                if(QString(player.name.c_str()) == winner)
                    player.groupWins++;
                else
                    player.groupLosses++;

                player.KOs += resultsWindow.getKOs(j + 1);

                player.save(playerDir.canonicalPath().toStdString() + "/" + player.name);
            }
	}
    }
}

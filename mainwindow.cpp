#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <time.h>
#include "player.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    playerDir("./players")
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addPlayer()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removePlayer()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->fightButton, SIGNAL(clicked()), this, SLOT(fight()));
    connect(ui->refreshButton, SIGNAL(clicked()), this, SLOT(refreshPlayers()));


    refreshPlayers();

    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::refreshPlayers(void)
{
    ui->playerList->clear();
    players.clear();

    // Loads current players and displays them

    QFileInfoList list = playerDir.entryInfoList(QDir::Files);
    for(int i = 0; i < list.size(); ++i)
    {
	if(list.at(i).completeSuffix().compare("brawler") != 0) continue;
	Player newPlayer("");
	newPlayer.load(String(String("players/") + list.at(i).baseName().toStdString()).c_str());
	players.append(newPlayer);
    }

    for(int i = 0; i < players.size(); ++i)
    {
	ui->playerList->addItem(players.at(i).name.c_str());
    }
}

void MainWindow::addPlayer()
{
    QString name = ui->playerEdit->text();

    if(name == "")
        return;

    if(ui->playerList->findItems(name, Qt::MatchExactly).size() > 0)
        return;

    // Saves player
    Player newPlayer(name.toStdString());
    newPlayer.save(playerDir.canonicalPath().toStdString() + "/" + name.toStdString());


    refreshPlayers();

    ui->playerEdit->clear();

    if(ui->playerList->count() >= 15)
        ui->addButton->setEnabled(false);
}

void MainWindow::removePlayer()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to delete the selected players?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::No)
        return;

    QList<QListWidgetItem*> selection = ui->playerList->selectedItems();
    while(!selection.isEmpty())
    {
	QListWidgetItem* item = selection.takeFirst();
        QString dir = playerDir.canonicalPath() + "/" + item->text() + ".brawler";
        QFile file(dir);
	file.remove();
	delete item;
    }

    refreshPlayers();

    if(ui->playerList->count() < 15)
        ui->addButton->setEnabled(true);
}

void MainWindow::fight()
{
    QList<QListWidgetItem*> selection = ui->playerList->selectedItems();
    if(selection.count() <= 1)
    {
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setText("You need to select more players from the list!");
        msgBox.exec();
    }

    else if(selection.count() >= 5)
    {
        QMessageBox msgBox;
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setText("A " + QString().setNum(players.count()) + " player game?? LOL!");
        msgBox.exec();
    }

    else
    {
        Game *game = new Game(selection);
        game->generateRandomCharacters();
        game->getGameResults();
        delete game;
    }
}

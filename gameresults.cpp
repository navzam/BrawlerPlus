#include "gameresults.h"
#include "ui_gameresults.h"

GameResults::GameResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameResults)
{
    ui->setupUi(this);
    numberOfPlayers = 0;

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

GameResults::~GameResults()
{
    delete ui;
}

void GameResults::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void GameResults::addPlayer(QString playerName)
{
    ui->PlayerLabel[numberOfPlayers]->setEnabled(true);
    ui->KOLabel[numberOfPlayers]->setEnabled(true);
    ui->KOEdit[numberOfPlayers]->setEnabled(true);

    ui->winnerSelect->addItem(playerName);
    ui->PlayerLabel[numberOfPlayers]->setText(playerName);
    numberOfPlayers++;
}

QString GameResults::getWinner()
{
    return ui->winnerSelect->currentText();
}

int GameResults::getKOs(int player)
{
    return ui->KOEdit[player - 1]->text().toInt();
}

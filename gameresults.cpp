#include "gameresults.h"
#include "ui_gameresults.h"

GameResults::GameResults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameResults)
{
    ui->setupUi(this);
    numberOfPlayers = 0;

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
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
    ui->KOSpinBox[numberOfPlayers]->setEnabled(true);

    ui->winnerSelect->addItem(playerName);
    ui->PlayerLabel[numberOfPlayers]->setText(playerName + "      ");
    numberOfPlayers++;
}

QString GameResults::getWinner()
{
    return ui->winnerSelect->currentText();
}

int GameResults::getKOs(int player)
{
    return ui->KOSpinBox[player - 1]->value();
}

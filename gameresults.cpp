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

    PlayerLabel[0] = ui->Player1Label;
    PlayerLabel[1] = ui->Player2Label;
    PlayerLabel[2] = ui->Player3Label;
    PlayerLabel[3] = ui->Player4Label;

    KOLabel[0] = ui->KOLabel1;
    KOLabel[1] = ui->KOLabel2;
    KOLabel[2] = ui->KOLabel3;
    KOLabel[3] = ui->KOLabel4;

    KOSpinBox[0] = ui->KOSpinBox1;
    KOSpinBox[1] = ui->KOSpinBox2;
    KOSpinBox[2] = ui->KOSpinBox3;
    KOSpinBox[3] = ui->KOSpinBox4;

    for(int i = 0; i < 4; ++i)
    {
	PlayerLabel[i]->setEnabled(false);
	KOLabel[i]->setEnabled(false);
	KOSpinBox[i]->setEnabled(false);
    }
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
    PlayerLabel[numberOfPlayers]->setEnabled(true);
    KOLabel[numberOfPlayers]->setEnabled(true);
    KOSpinBox[numberOfPlayers]->setEnabled(true);

    ui->winnerSelect->addItem(playerName);
    PlayerLabel[numberOfPlayers]->setText(playerName + "      ");
    numberOfPlayers++;
}

QString GameResults::getWinner()
{
    return ui->winnerSelect->currentText();
}

int GameResults::getKOs(int player)
{
    return KOSpinBox[player - 1]->value();
}

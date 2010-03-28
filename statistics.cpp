#include "statistics.h"
#include "ui_statistics.h"
#include "piechart.h"

Statistics::Statistics(QList<Player> players, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Statistics),
    m_players(players)
{
    m_ui->setupUi(this);

    m_ui->tabs->removeTab(0);

    m_ui->tabs->addTab(createGames(), QIcon(), "Games");

    m_ui->tabs->addTab(createGamesLost(), QIcon(), "Losses");
}

Statistics::~Statistics()
{
    delete m_ui;
}

void Statistics::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QWidget* Statistics::createGames()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    for(int i = 0; i < m_players.size(); ++i)
    {
	Player player = m_players.at(i);
	uint32 gamesWon = player.getGamesWon();
	uint32 gamesLost = player.getGamesLost();
	PieChart* pieChart = new PieChart(player.name.c_str());
	pieChart->addItem(QPair<QString, int>("Wins", gamesWon));
	pieChart->addItem(QPair<QString, int>("Losses", gamesLost));
	layout->addWidget(pieChart);
    }

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

QWidget* Statistics::createGamesLost()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    for(int i = 0; i < m_players.size(); ++i)
    {
	Player player = m_players.at(i);
	PieChart* pieChart = new PieChart(player.name.c_str() + tr(" Losses"));
	for (Player::MapType::const_iterator it = player.losses.begin(); it != player.losses.end(); ++it)
	{
	    pieChart->addItem(QPair<QString, int>((*it).first.value.c_str(), (*it).second.value));
	}
	layout->addWidget(pieChart);
    }

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

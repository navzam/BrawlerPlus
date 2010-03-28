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

    if(players.size() == 2)
    {
	Player player1 = m_players.at(0);
	Player player2 = m_players.at(1);
	m_ui->tabs->addTab(create1vs1Comparison(), QIcon(), tr(player1.name.c_str()) + tr(" vs ") + tr(player2.name.c_str()));
    }

    m_ui->tabs->addTab(createGroupWins(), QIcon(), "Group Wins");

    m_ui->tabs->addTab(createGroupLosses(), QIcon(), "Group Losses");

    m_ui->tabs->addTab(create1vs1Wins(), QIcon(), "1 vs 1 Wins");

    m_ui->tabs->addTab(create1vs1Losses(), QIcon(), "1 vs 1 Losses");

    m_ui->tabs->addTab(createKOs(), QIcon(), "KOs");
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

QWidget* Statistics::createGroupWins()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    PieChart* pieChart = new PieChart("Group Wins");
    for(int i = 0; i < m_players.size(); ++i)
    {
	Player player = m_players.at(i);
        pieChart->addItem(QPair<QString, int>(player.name.c_str(), player.groupWins));
    }
    layout->addWidget(pieChart);

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

QWidget* Statistics::createGroupLosses()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    PieChart* pieChart = new PieChart("Group Losses");
    for(int i = 0; i < m_players.size(); ++i)
    {
        Player player = m_players.at(i);
        pieChart->addItem(QPair<QString, int>(player.name.c_str(), player.groupLosses));
    }
    layout->addWidget(pieChart);

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

QWidget* Statistics::create1vs1Wins()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    for(int i = 0; i < m_players.size(); ++i)
    {
        Player player = m_players.at(i);
        PieChart* pieChart = new PieChart(player.name.c_str() + tr(" Wins"));
        for (Player::MapType::const_iterator it = player.wins.begin(); it != player.wins.end(); ++it)
        {
            pieChart->addItem(QPair<QString, int>((*it).first.value.c_str(), (*it).second.value));
        }
        layout->addWidget(pieChart);
    }

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

QWidget* Statistics::create1vs1Losses()
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

QWidget* Statistics::createKOs()
{
    QVBoxLayout* layout = new QVBoxLayout();
    //layout->addWidget();
    PieChart* KOChart = new PieChart("KOs");
    PieChart* KOPGChart = new PieChart("KOs Per Game");
    for(int i = 0; i < m_players.size(); ++i)
    {
        Player player = m_players.at(i);
        KOChart->addItem(QPair<QString, int>(player.name.c_str(), player.KOs));
        if(player.getGamesPlayed() > 0)
            KOPGChart->addItem(QPair<QString, int>(player.name.c_str(), ((double)player.KOs / player.getGamesPlayed()) + 0.5));
    }
    layout->addWidget(KOChart);
    layout->addWidget(KOPGChart);

    QWidget* holder = new QWidget(this);
    holder->setLayout(layout);

    return holder;
}

QWidget* Statistics::create1vs1Comparison()
{
    Player player1 = m_players.at(0);
    Player player2 = m_players.at(1);
    PieChart* pieChart = new PieChart(player1.name.c_str() + tr(" vs ") + player2.name.c_str());
    pieChart->addItem(QPair<QString, int>(tr(player1.name.c_str()) + tr(" Wins"), player1.wins[SString(player2.name)].value));
    pieChart->addItem(QPair<QString, int>(tr(player2.name.c_str()) + tr(" Wins"), player2.wins[SString(player1.name)].value));
    return pieChart;
}

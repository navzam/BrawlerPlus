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

    m_ui->tabs->addTab(createGroupWins(), QIcon(), "Group Wins");

    m_ui->tabs->addTab(createGroupLosses(), QIcon(), "Group Losses");

    m_ui->tabs->addTab(create1vs1Wins(), QIcon(), "1 vs 1 Wins");

    m_ui->tabs->addTab(create1vs1Losses(), QIcon(), "1 vs 1 Losses");
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

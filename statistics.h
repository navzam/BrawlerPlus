#ifndef STATISTICS_H
#define STATISTICS_H

#include <QtGui/QWidget>
#include "player.h"

namespace Ui {
    class Statistics;
}

class Statistics : public QWidget {
    Q_OBJECT
public:
    Statistics(QList<Player> players, QWidget *parent = 0);
    ~Statistics();

protected:
    void changeEvent(QEvent *e);
    QWidget* createGames();
    QWidget* createGamesLost();

private:
    Ui::Statistics *m_ui;
    QList<Player> m_players;
};

#endif // STATISTICS_H

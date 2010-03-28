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
    QWidget* createGroupWins();
    QWidget* createGroupLosses();
    QWidget* create1vs1Wins();
    QWidget* create1vs1Losses();
    QWidget* create1vs1Comparison();

private:
    Ui::Statistics *m_ui;
    QList<Player> m_players;
};

#endif // STATISTICS_H

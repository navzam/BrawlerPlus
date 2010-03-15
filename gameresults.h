#ifndef GAMERESULTS_H
#define GAMERESULTS_H

#include <QDialog>

namespace Ui {
    class GameResults;
}

class GameResults : public QDialog {
    Q_OBJECT
public:
    GameResults(QWidget *parent = 0);
    ~GameResults();

    void addPlayer(QString);
    QString getWinner();
    int getKOs(int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::GameResults *ui;
    int numberOfPlayers;
};

#endif // GAMERESULTS_H

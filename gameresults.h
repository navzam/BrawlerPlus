#ifndef GAMERESULTS_H
#define GAMERESULTS_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>

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

    QSpinBox* KOSpinBox[4];
    QLabel* PlayerLabel[4];
    QLabel* KOLabel[4];

    int numberOfPlayers;
};

#endif // GAMERESULTS_H

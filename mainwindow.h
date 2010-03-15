#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

class Player;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);


private:
    Ui::MainWindow *ui;
    QList<Player> players;
    QDir playerDir;

private slots:
    void addPlayer();
    void removePlayer();
    void fight();
    void refreshPlayers(void);
};

#endif // MAINWINDOW_H

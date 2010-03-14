#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "characters.h"
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addPlayer()));
    connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removePlayer()));
    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->fightButton, SIGNAL(clicked()), this, SLOT(fight()));

    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::addPlayer()
{
    QString name = ui->playerEdit->text();

    if(name == "")
        return;

    if(ui->playerList->findItems(name, Qt::MatchExactly).size() > 0)
        return;

    ui->playerList->addItem(name);
    ui->playerEdit->clear();

    if(ui->playerList->count() >= 15)
        ui->addButton->setEnabled(false);

}

void MainWindow::removePlayer()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to delete the selected players?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::No)
        return;

    QList<QListWidgetItem*> selection = ui->playerList->selectedItems();
    while(!selection.isEmpty())
        delete selection.takeFirst();

    if(ui->playerList->count() < 15)
        ui->addButton->setEnabled(true);
}

void MainWindow::fight()
{
}

/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sun Mar 14 21:09:38 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Player;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionPreferences;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *playerEdit;
    QListWidget *playerList;
    QPushButton *fightButton;
    QVBoxLayout *verticalLayout_3;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *refreshButton;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuBrawler_Plus;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(285, 420);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/WindowIcon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew_Player = new QAction(MainWindow);
        actionNew_Player->setObjectName(QString::fromUtf8("actionNew_Player"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionQuit->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/QuitIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/AboutIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(19, 20, 241, 351));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setMargin(11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        playerEdit = new QLineEdit(horizontalLayoutWidget);
        playerEdit->setObjectName(QString::fromUtf8("playerEdit"));
        playerEdit->setMaxLength(20);

        verticalLayout->addWidget(playerEdit);

        playerList = new QListWidget(horizontalLayoutWidget);
        playerList->setObjectName(QString::fromUtf8("playerList"));
        playerList->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(playerList);

        fightButton = new QPushButton(horizontalLayoutWidget);
        fightButton->setObjectName(QString::fromUtf8("fightButton"));

        verticalLayout->addWidget(fightButton);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_3->addWidget(addButton);

        removeButton = new QPushButton(horizontalLayoutWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout_3->addWidget(removeButton);

        refreshButton = new QPushButton(horizontalLayoutWidget);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));

        verticalLayout_3->addWidget(refreshButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 285, 27));
        menuBrawler_Plus = new QMenu(menuBar);
        menuBrawler_Plus->setObjectName(QString::fromUtf8("menuBrawler_Plus"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuBrawler_Plus->menuAction());
        menuBrawler_Plus->addAction(actionPreferences);
        menuBrawler_Plus->addAction(actionAbout);
        menuBrawler_Plus->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Brawler Plus", 0, QApplication::UnicodeUTF8));
        actionNew_Player->setText(QApplication::translate("MainWindow", "New Player", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0, QApplication::UnicodeUTF8));
        fightButton->setText(QApplication::translate("MainWindow", "Brawl!", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        addButton->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        addButton->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        refreshButton->setText(QApplication::translate("MainWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        menuBrawler_Plus->setTitle(QApplication::translate("MainWindow", "Brawler Plus", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

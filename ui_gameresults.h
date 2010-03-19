/********************************************************************************
** Form generated from reading UI file 'gameresults.ui'
**
** Created: Thu Mar 18 21:57:43 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMERESULTS_H
#define UI_GAMERESULTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameResults
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *winnerLabel;
    QComboBox *winnerSelect;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    
    QLabel *PlayerLabel[4];
    QLabel *KOLabel[4];
    QLineEdit *KOEdit[4];

    void setupUi(QDialog *GameResults)
    {
        if (GameResults->objectName().isEmpty())
            GameResults->setObjectName(QString::fromUtf8("GameResults"));
        GameResults->resize(360, 290);
        verticalLayoutWidget = new QWidget(GameResults);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 341, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        winnerLabel = new QLabel(verticalLayoutWidget);
        winnerLabel->setObjectName(QString::fromUtf8("winnerLabel"));

        horizontalLayout->addWidget(winnerLabel);

        winnerSelect = new QComboBox(verticalLayoutWidget);
        winnerSelect->setObjectName(QString::fromUtf8("winnerSelect"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(winnerSelect->sizePolicy().hasHeightForWidth());
        winnerSelect->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(winnerSelect);

        horizontalSpacer_2 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        PlayerLabel[0] = new QLabel(verticalLayoutWidget);
        PlayerLabel[0]->setObjectName(QString::fromUtf8("Player1Label"));
        PlayerLabel[0]->setEnabled(false);

        gridLayout->addWidget(PlayerLabel[0], 0, 0, 1, 1);

        PlayerLabel[1] = new QLabel(verticalLayoutWidget);
        PlayerLabel[1]->setObjectName(QString::fromUtf8("Player2Label"));
        PlayerLabel[1]->setEnabled(false);

        gridLayout->addWidget(PlayerLabel[1], 2, 0, 1, 1);

        PlayerLabel[2] = new QLabel(verticalLayoutWidget);
        PlayerLabel[2]->setObjectName(QString::fromUtf8("Player3Label"));
        PlayerLabel[2]->setEnabled(false);

        gridLayout->addWidget(PlayerLabel[2], 3, 0, 1, 1);

        PlayerLabel[3] = new QLabel(verticalLayoutWidget);
        PlayerLabel[3]->setObjectName(QString::fromUtf8("Player4Label"));
        PlayerLabel[3]->setEnabled(false);

        gridLayout->addWidget(PlayerLabel[3], 4, 0, 1, 1);

        KOLabel[0] = new QLabel(verticalLayoutWidget);
        KOLabel[0]->setObjectName(QString::fromUtf8("KOLabel1"));
        KOLabel[0]->setEnabled(false);

        gridLayout->addWidget(KOLabel[0], 0, 2, 1, 1);

        KOLabel[1] = new QLabel(verticalLayoutWidget);
        KOLabel[1]->setObjectName(QString::fromUtf8("KOLabel2"));
        KOLabel[1]->setEnabled(false);

        gridLayout->addWidget(KOLabel[1], 2, 2, 1, 1);

        KOLabel[2] = new QLabel(verticalLayoutWidget);
        KOLabel[2]->setObjectName(QString::fromUtf8("KOLabel3"));
        KOLabel[2]->setEnabled(false);

        gridLayout->addWidget(KOLabel[2], 3, 2, 1, 1);

        KOLabel[3] = new QLabel(verticalLayoutWidget);
        KOLabel[3]->setObjectName(QString::fromUtf8("KOLabel4"));
        KOLabel[3]->setEnabled(false);

        gridLayout->addWidget(KOLabel[3], 4, 2, 1, 1);

        KOEdit[0] = new QLineEdit(verticalLayoutWidget);
        KOEdit[0]->setObjectName(QString::fromUtf8("KOEdit1"));
        KOEdit[0]->setMaxLength(2);
        KOEdit[0]->setEnabled(false);

        gridLayout->addWidget(KOEdit[0], 0, 3, 1, 1);

        KOEdit[1] = new QLineEdit(verticalLayoutWidget);
        KOEdit[1]->setObjectName(QString::fromUtf8("KOEdit2"));
        KOEdit[1]->setMaxLength(2);
        KOEdit[1]->setEnabled(false);

        gridLayout->addWidget(KOEdit[1], 2, 3, 1, 1);

        KOEdit[2] = new QLineEdit(verticalLayoutWidget);
        KOEdit[2]->setObjectName(QString::fromUtf8("KOEdit3"));
        KOEdit[2]->setMaxLength(2);
        KOEdit[2]->setEnabled(false);

        gridLayout->addWidget(KOEdit[2], 3, 3, 1, 1);

        KOEdit[3] = new QLineEdit(verticalLayoutWidget);
        KOEdit[3]->setObjectName(QString::fromUtf8("KOEdit4"));
        KOEdit[3]->setMaxLength(2);
        KOEdit[3]->setEnabled(false);

        gridLayout->addWidget(KOEdit[3], 4, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 1);

        retranslateUi(GameResults);

        QMetaObject::connectSlotsByName(GameResults);
    } // setupUi

    void retranslateUi(QDialog *GameResults)
    {
        GameResults->setWindowTitle(QApplication::translate("GameResults", "Dialog", 0, QApplication::UnicodeUTF8));
        winnerLabel->setText(QApplication::translate("GameResults", "Winner:", 0, QApplication::UnicodeUTF8));
        PlayerLabel[0]->setText(QApplication::translate("GameResults", "Player 1:            ", 0, QApplication::UnicodeUTF8));
        PlayerLabel[1]->setText(QApplication::translate("GameResults", "Player 2:            ", 0, QApplication::UnicodeUTF8));
        PlayerLabel[2]->setText(QApplication::translate("GameResults", "Player 3:            ", 0, QApplication::UnicodeUTF8));
        PlayerLabel[3]->setText(QApplication::translate("GameResults", "Player 4:            ", 0, QApplication::UnicodeUTF8));
        KOLabel[0]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        KOLabel[1]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        KOLabel[2]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        KOLabel[3]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GameResults", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameResults: public Ui_GameResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERESULTS_H

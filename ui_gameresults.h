/********************************************************************************
** Form generated from reading UI file 'gameresults.ui'
**
** Created: Thu Mar 18 12:13:29 2010
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
    QSpacerItem *horizontalSpacer_12;
    QLabel *winnerLabel;
    QComboBox *winnerSelect;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_10;

    QLabel *PlayerLabel[4];
    QLabel *KOLabel[4];
    QLineEdit *KOEdit[4];

    void setupUi(QDialog *GameResults)
    {
        if (GameResults->objectName().isEmpty())
            GameResults->setObjectName(QString::fromUtf8("GameResults"));
        GameResults->resize(360, 300);
        verticalLayoutWidget = new QWidget(GameResults);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 321, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_12 = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

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

        horizontalSpacer = new QSpacerItem(QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        PlayerLabel[0] = new QLabel(verticalLayoutWidget);
        PlayerLabel[0]->setObjectName(QString::fromUtf8("Player1Label"));
        PlayerLabel[0]->setEnabled(true);

        horizontalLayout_5->addWidget(PlayerLabel[0]);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        KOLabel[0] = new QLabel(verticalLayoutWidget);
        KOLabel[0]->setObjectName(QString::fromUtf8("KOLabel1"));

        horizontalLayout_5->addWidget(KOLabel[0]);

        KOEdit[0] = new QLineEdit(verticalLayoutWidget);
        KOEdit[0]->setObjectName(QString::fromUtf8("KOEdit1"));
        KOEdit[0]->setEnabled(true);
        KOEdit[0]->setMaxLength(2);

        horizontalLayout_5->addWidget(KOEdit[0]);

        horizontalSpacer_3 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        PlayerLabel[1] = new QLabel(verticalLayoutWidget);
        PlayerLabel[1]->setObjectName(QString::fromUtf8("Player2Label"));

        horizontalLayout_4->addWidget(PlayerLabel[1]);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        KOLabel[1] = new QLabel(verticalLayoutWidget);
        KOLabel[1]->setObjectName(QString::fromUtf8("KOLabel2"));

        horizontalLayout_4->addWidget(KOLabel[1]);

        KOEdit[1] = new QLineEdit(verticalLayoutWidget);
        KOEdit[1]->setObjectName(QString::fromUtf8("KOEdit2"));
        KOEdit[1]->setMaxLength(2);

        horizontalLayout_4->addWidget(KOEdit[1]);

        horizontalSpacer_5 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PlayerLabel[2] = new QLabel(verticalLayoutWidget);
        PlayerLabel[2]->setObjectName(QString::fromUtf8("Player3Label"));

        horizontalLayout_3->addWidget(PlayerLabel[2]);

        horizontalSpacer_6 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        KOLabel[2] = new QLabel(verticalLayoutWidget);
        KOLabel[2]->setObjectName(QString::fromUtf8("KOLabel3"));

        horizontalLayout_3->addWidget(KOLabel[2]);

        KOEdit[2] = new QLineEdit(verticalLayoutWidget);
        KOEdit[2]->setObjectName(QString::fromUtf8("KOEdit3"));
        KOEdit[2]->setMaxLength(2);

        horizontalLayout_3->addWidget(KOEdit[2]);

        horizontalSpacer_7 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PlayerLabel[3] = new QLabel(verticalLayoutWidget);
        PlayerLabel[3]->setObjectName(QString::fromUtf8("Player4Label"));

        horizontalLayout_2->addWidget(PlayerLabel[3]);

        horizontalSpacer_8 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        KOLabel[3] = new QLabel(verticalLayoutWidget);
        KOLabel[3]->setObjectName(QString::fromUtf8("KOLabel4"));

        horizontalLayout_2->addWidget(KOLabel[3]);

        KOEdit[3] = new QLineEdit(verticalLayoutWidget);
        KOEdit[3]->setObjectName(QString::fromUtf8("KOEdit4"));

        horizontalLayout_2->addWidget(KOEdit[3]);

        horizontalSpacer_9 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(GameResults);

        QMetaObject::connectSlotsByName(GameResults);
    } // setupUi

    void retranslateUi(QDialog *GameResults)
    {
        GameResults->setWindowTitle(QApplication::translate("GameResults", "Dialog", 0, QApplication::UnicodeUTF8));
        winnerLabel->setText(QApplication::translate("GameResults", "Winner:", 0, QApplication::UnicodeUTF8));
        PlayerLabel[0]->setText(QApplication::translate("GameResults", "Player1:", 0, QApplication::UnicodeUTF8));
        KOLabel[0]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        PlayerLabel[1]->setText(QApplication::translate("GameResults", "Player2:", 0, QApplication::UnicodeUTF8));
        KOLabel[1]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        PlayerLabel[2]->setText(QApplication::translate("GameResults", "Player3:", 0, QApplication::UnicodeUTF8));
        KOLabel[2]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        PlayerLabel[3]->setText(QApplication::translate("GameResults", "Player4:", 0, QApplication::UnicodeUTF8));
        KOLabel[3]->setText(QApplication::translate("GameResults", "KOs:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("GameResults", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameResults: public Ui_GameResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMERESULTS_H

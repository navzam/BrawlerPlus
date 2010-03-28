/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created: Sun Mar 28 11:33:52 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistics
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabs;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Statistics)
    {
        if (Statistics->objectName().isEmpty())
            Statistics->setObjectName(QString::fromUtf8("Statistics"));
        Statistics->resize(701, 446);
        verticalLayout = new QVBoxLayout(Statistics);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabs = new QTabWidget(Statistics);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabs->addTab(tab, QString());

        verticalLayout->addWidget(tabs);


        retranslateUi(Statistics);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Statistics);
    } // setupUi

    void retranslateUi(QWidget *Statistics)
    {
        Statistics->setWindowTitle(QApplication::translate("Statistics", "Statistics", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tab), QApplication::translate("Statistics", "Tab 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Statistics: public Ui_Statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H

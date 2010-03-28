#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>

class PieChart : public QWidget
{
public:
    PieChart(QString name);
    void addItem(QPair<QString, int> item);

protected:
    void paintEvent(QPaintEvent *event);
    int getTotal();

private:
    QList<QPair<QString, int> > m_items;
    QString m_name;
};

#endif // PIECHART_H

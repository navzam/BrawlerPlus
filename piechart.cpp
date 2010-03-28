#include "piechart.h"
#include <QPainter>

PieChart::PieChart(QString name)
	: m_name(name)
{
}

void PieChart::addItem(QPair<QString, int> item)
{
    m_items.append(item);
}

void PieChart::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int size = width() - 150 > height() ? height() : width() - 150;

    painter.drawEllipse(1, 1, size - 1, size - 1);

    int cX = size / 2;
    int cY = size / 2;

    double angle = 0.0;

    int total = getTotal();

    for(int i = 0; i < m_items.size(); ++i)
    {
	QPair<QString, int> current = m_items.at(i);
	QString name = current.first;
	int amt = current.second;

	double itemAngle = (((double)amt) / total) * 360;

	int colorI = (((double)i) / m_items.size()) * 255;

	QColor color = QColor(colorI, colorI, 255 - colorI / 2);
	color = color.lighter();
	painter.setBrush(QBrush(color));
	painter.drawPie(1, 1, size - 1, size - 1, int(angle * 16), int(itemAngle * 16));
	painter.fillRect(width() - 140, i * 30, 20, 20, color);
	painter.drawText(width() - 110, i * 30 + 15, QString().setNum(amt) + " " + name);

	angle += itemAngle;
    }

    QFont font = painter.font();
    font.setBold(true);
    font.setPointSize(font.pointSize() + 10);
    painter.setFont(font);
    painter.drawText(size - 10, size, m_name);
}

int PieChart::getTotal()
{
    int ret = 0;
    for(int i = 0; i < m_items.size(); ++i)
    {
	ret += m_items.at(i).second;
    }
    return ret;
}

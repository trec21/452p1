#include "painter.h"

Painter::Painter(QWidget *parent)
    : QWidget(parent), x (0),  y(0)
{
    trigger = false;
}

void Painter::addPoint(int newX, int newY) {
    x = newX;
    y = newY;
    trigger = true;
}

void Painter::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    if (trigger)
    {
        QPainter painter(this);
        QPen pen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        painter.drawPoint(x, y);
    }
    trigger = false;
}

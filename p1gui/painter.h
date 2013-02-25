#ifndef PAINTER_H
#define PAINTER_H
#include <QWidget>
#include <QPainter>

class Painter : public QWidget {
Q_OBJECT
public:
    Painter(QWidget *parent);
    void addPoint(int newX, int newY);

protected:
    void paintEvent(QPaintEvent *event);

private:
    bool trigger;
    int x, y;
};


#endif

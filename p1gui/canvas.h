#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "link.h"
#include "axis.h"
#include "painter.h"

class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = 0);
    void initialize();
    int h, w;
signals:

public slots:


    void getAxis();
    void updateList();
    void paint();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << event->scenePos();
    }
    void paintEvent(QPaintEvent *event);

private:
    Painter *painter;
    std::vector<Link*> links;
    std::vector<Axis*> axes;
    bool paintTrigger;

    void updateLinks();

};

#endif // CANVAS_H

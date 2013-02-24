#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "link.h"
#include "axis.h"


class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = 0);
    void initialize();

signals:

public slots:



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << event->scenePos();
    }

private:
    std::vector<Link*> links;
    std::vector<Axis*> axes;

    void updateLinks();
};

#endif // CANVAS_H

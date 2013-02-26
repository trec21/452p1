#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QListWidget>
#include <QDebug>
#include "link.h"
#include "axis.h"


class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent = 0);
    void initialize();
    void setAxesList(QListWidget* list);

signals:

public slots:




    void rotateCW();
    void rotateCCW();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {
        qDebug() << event->scenePos();
    }

private:
    std::vector<Link*> links;
    std::vector<Axis*> axes;
    QListWidget* axesList;
    void updateList();
    int getAxis();
    void setUpAxes();

    void updateLinks(Link *_link, double _angle);
    void rotate_axis(Axis* base_axis, Axis* rotated_axis, double degrees, Link* link);
};

#endif // CANVAS_H

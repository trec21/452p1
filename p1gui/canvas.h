#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QListWidget>
#include <QDebug>

#include "link.h"
#include "axis.h"
#include "painter.h"

class Canvas : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canvas(QObject *parent);
    void initialize();
    int h, w;
    void setAxesList(QListWidget* list);

signals:

public slots:

    void paint();

    void rotateCW();
    void rotateCCW();

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


    QListWidget* axesList;
    void updateList();
    int getAxis();
    void setUpAxes();

    void updateLinks(Link *_link, double _angle);
    void rotate_axis(Axis* base_axis, Axis* rotated_axis, double degrees, Link* link);

};

#endif // CANVAS_H

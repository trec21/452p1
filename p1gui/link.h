#ifndef LINK_H
#define LINK_H
#include <QGraphicsItem>

using namespace std;

class Link : public QGraphicsEllipseItem {

public:
    explicit Link(QGraphicsEllipseItem* ellipse)
        : QGraphicsEllipseItem(ellipse) {

    }

    // void boundingRect() const;

    //void rotate(QPoint bottom, QPoint top);
};

#endif // LINK_H

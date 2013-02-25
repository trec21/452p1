#ifndef LINK_H
#define LINK_H
#include <QGraphicsItem>
#include <vector>
#include <math.h>

#include "armadillo"
#include <iostream>
#include "axis.h"

using namespace arma;
using namespace std;

#define DEGREES *3.14159265/180

class Link {

public:

    int length;
    double link_number;
    double _a;
    double _alpha;
    double _d;
    double _theta;
    QGraphicsEllipseItem* ellipse;

    // front is the initial 'top' axis and back the 'bottom'
    Axis* frontAxis;
    Axis* backAxis;

    Link();

    /* Getters Setters */
    double x() {
        return ellipse->x();
    }
    double y() {
        return ellipse->y();
    }

    void setX(double x) {
        ellipse->setX(x);
    }

    void setY(double y) {
        ellipse->setY(y);
    }

    Link(int origin_x, int origin_y, int length);

    void setDH(int a, int alpha, int d, int theta);

    vector<double> getNextAxisPoint();
    // void boundingRect() const;

    //void rotate(QPoint bottom, QPoint top);
};

#endif // LINK_H

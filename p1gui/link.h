#ifndef LINK_H
#define LINK_H
#include <QGraphicsItem>
#include <vector>
#include <math.h>

#include "armadillo"
#include <iostream>
using namespace arma;
using namespace std;

#define DEGREES *3.14159265/180

class Link {

public:

    int length;
    int loc_x;
    int loc_y;
    double link_number;
    double _a;
    double _alpha;
    double _d;
    double _theta;
    QGraphicsEllipseItem* ellipse;

    Link();

    Link(int origin_x, int origin_y, int l);

    void setDH(int a, int alpha, int d, int theta);
    // void boundingRect() const;

    //void rotate(QPoint bottom, QPoint top);
};

#endif // LINK_H

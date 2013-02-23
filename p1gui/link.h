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

class Link : public QGraphicsEllipseItem {

public:
    explicit Link(QGraphicsEllipseItem* ellipse)
        : QGraphicsEllipseItem(ellipse) {

    }
    static vector<Link*> Links;
    int length;
    int loc_x;
    int loc_y;
    double link_number;
    double _a;
    double _alpha;
    double _d;
    double _theta;

    Link()
    {
        Links.push_back(this);
        link_number = Links.size() - 1;
    }

    Link(int origin_x, int origin_y, int l)
    {
        Links.push_back(this);
        length = l;
        link_number = Links.size() - 1;
    }

    void setDH(int a, int alpha, int d, int theta)
    {
        _alpha = alpha;
        _a = a;
        _d = d;
        _theta = theta;
    }
    // void boundingRect() const;

    //void rotate(QPoint bottom, QPoint top);
};

class Axis
{
public:

    static vector<Axis*> Axes;
    double axis_number;
    double orientation;
    int loc_x;
    int loc_y;
    mat rot_Z;

    Axis()
    {
        Axes.push_back(this);
        axis_number = Axes.size() - 1;
    }

    Axis(int origin_x, int origin_y, int l)
    {
        loc_x = origin_x;
        loc_y = origin_y;
        Axes.push_back(this);
        axis_number = Axes.size() - 1;
    }

    void rotate(double d)
    {
        /*returns the position of the next axis
        needs to look up the length of the link between the axes
        and the current axis' orientation
        and generate the rotation matrix to rotate that vector
        */
        rot_Z
            << cos(d DEGREES) << -1*sin(d DEGREES) << 0 << endr
            << sin(d DEGREES) << cos(d DEGREES) << 0 << endr
            << 0 << 0 << 1 << endr;

        mat current_loc;
        current_loc
            << loc_x << endr
            << loc_y << endr
            << 0 << endr;

        rot_Z.print("ROT_Z:");
        cout<<endl;
        current_loc.print("Axis Location");

        mat result = rot_Z * current_loc;
        result.print("New Location:");

        loc_x = result(0,0);
        loc_y = result(1,0);
    }


};

#endif // LINK_H

#include "link.h"
#include "axis.h"

Link::Link()
{

}

Link::Link(int origin_x, int origin_y, int _length)
{
    length = _length;
}

void Link::setDH(int a, int alpha, int d, int theta)
{
    _alpha = alpha;
    _a = a;
    _d = d;
    _theta = theta;
}



vector<double> Link::getNextAxisPoint()
{
    //needs to update front axis
    vector<double> coords;
    double offset = this->length;
    double o = orientation;
    double current_x = backAxis->loc_x;
    double current_y = backAxis->loc_y;
    double new_x = current_x + offset * sin(orientation DEGREES);
    double new_y = current_y + offset * cos(orientation DEGREES);

    //updating front axis
    frontAxis->loc_x = -1*new_x;
    frontAxis->loc_y = new_y;

    coords.push_back(new_x);
    coords.push_back(new_y);
    return coords;
}


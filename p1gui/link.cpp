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
    vector<double> coords;
    double offset = this->length DEGREES;
    double new_x = backAxis->loc_x + cos(offset);
    double new_y = backAxis->loc_y + sin(offset);
    coords.push_back(new_x);
    coords.push_back(new_y);
    return coords;
}


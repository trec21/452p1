#include "link.h"
#include "axis.h"

Link::Link()
{

}

Link::Link(int origin_x, int origin_y, int l)
{
    length = l;
}

void Link::setDH(int a, int alpha, int d, int theta)
{
    _alpha = alpha;
    _a = a;
    _d = d;
    _theta = theta;
}



vector<int> getNextAxisPoint(Axis* axis)
{
    vector<int> coords;
    int new_x = axis->loc_x + (int)cos(offset);
    int new_y = axis->loc_y + (int)sin(offset);
    coords.push_back(new_x);
    coords.push_back(new_y);
    return coords;
}


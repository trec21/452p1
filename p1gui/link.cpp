#include "link.h"
#include "axis.h"

Link::Link()
{
    Links.push_back(this);
    link_number = Links.size() - 1;
}

Link::Link(int origin_x, int origin_y, int l)
{
    Links.push_back(this);
    length = l;
    link_number = Links.size() - 1;
}

void Link::setDH(int a, int alpha, int d, int theta)
{
    _alpha = alpha;
    _a = a;
    _d = d;
    _theta = theta;
}



vector<int> getNextAxisPoint(Axis a)
{
    vector<int> coords;
    int offset = Link::Links[a.axis_number]->length DEGREES;
    int new_x = a.loc_x + (int)cos(offset);
    int new_y = a.loc_y + (int)sin(offset);
    coords.push_back(new_x);
    coords.push_back(new_y);
    return coords;
}

vector<Link*> Link::Links;
vector<Axis*> Axis::Axes;

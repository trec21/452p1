#include "link.h"




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

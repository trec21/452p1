#include "axis.h"

Axis::Axis()
{
    Axes.push_back(this);
    axis_number = Axes.size() - 1;
}

Axis::Axis(int origin_x, int origin_y, int l)
{
    loc_x = origin_x;
    loc_y = origin_y;
    Axes.push_back(this);
    axis_number = Axes.size() - 1;
}

void Axis::rotate(double d)
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

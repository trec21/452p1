#include "axis.h"

Axis::Axis()
{

}

Axis::Axis(int origin_x, int origin_y)
{
    loc_x = origin_x;
    loc_y = origin_y;
}

void Axis::rotate(Axis* axis, double d)
{
    /*
    returns the position of the next axis
    needs to look up the length of the link between the axes
    and the current axis' orientation
    and generate the rotation matrix to rotate that vector
    */

    mat rot_Z;
    rot_Z
        << cos(d DEGREES) << -1*sin(d DEGREES) << 0 << endr
        << sin(d DEGREES) << cos(d DEGREES) << 0 << endr
        << 0 << 0 << 1 << endr;

    mat current_loc;
    current_loc
        << axis->loc_x << endr
        << axis->loc_y << endr
        << 0 << endr;

    rot_Z.print("ROT_Z:");
    cout<<endl;
    current_loc.print("Axis Location");

    mat result = rot_Z * current_loc;
    result.print("New Location:");

    axis->loc_x = result(0,0);
    axis->loc_y = result(1,0);

}

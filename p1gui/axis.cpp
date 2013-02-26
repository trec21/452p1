#include "axis.h"

Axis::Axis()
{

}

Axis::Axis(int origin_x, int origin_y)
{
    loc_x = origin_x;
    loc_y = origin_y;
}

void Axis::rotate(Axis* axis, double degrees)
{
    /*
     * rotates the param axis with myself as the axis of rotation

    needs to look up the length of the link between the axes
    and the current axis' orientation
    and generate the rotation matrix to rotate that vector
    */

    mat rot_Z;
    rot_Z
        << cos(degrees DEGREES) << -1*sin(degrees DEGREES) << 0 << endr
        << sin(degrees DEGREES) << cos(degrees DEGREES) << 0 << endr
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

    Axis* next = axis->nextAxis;
    while (next != NULL) {

      // That substraction is the dx and dy
      // TODO This only works if links dont follow the same moving angle

        next->loc_x += result(0,0) - current_loc(0,0);
        next->loc_y += result(1,0) - current_loc(1,0);
        next = next->nextAxis;
    }
   /* vector<double> coords;
    double offset = this->length;
    double o = orientation;
    double current_x = backAxis->loc_x;
    double current_y = backAxis->loc_y;
    double new_x = current_x + offset * sin(orientation DEGREES);
    double new_y = current_y + offset * cos(orientation DEGREES);

    //updating front axis
    frontAxis->loc_x = new_x;
    frontAxis->loc_y = new_y;

    coords.push_back(new_x);
    coords.push_back(new_y);
*/
}

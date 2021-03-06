#ifndef AXIS_H
#define AXIS_H

#include <vector>
#include <math.h>

#include "armadillo"
#include <iostream>
#define DEGREES *3.14159265/180
using namespace arma;
using namespace std;

class Axis
{
public:

    double axis_number;
    double orientation;
    double loc_x;
    double loc_y;
    //mat rot_Z;

    Axis* nextAxis;

    Axis();

    Axis(int origin_x, int origin_y);

    void rotate(Axis* axis, double degrees);
};

#endif // AXIS_H

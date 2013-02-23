#ifndef AXIS_H
#define AXIS_H

class Axis
{
public:
    static vector<Axis*> Axes;
    double axis_number;
    double orientation;
    int loc_x;
    int loc_y;
    mat rot_Z;

    Axis();

    Axis(int origin_x, int origin_y, int l);

    void rotate(double d);
};

#endif // AXIS_H

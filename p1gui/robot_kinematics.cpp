#include <vector>
#include <math.h>

#include "armadillo"
#include <iostream>


using namespace arma;
using namespace std;

#define DEGREES *3.14159265/180
//kate and cesar will give me an axis and direction (cw/ccw)
//I will give them the three points of the axes (joints)

class Link
{
public:
	
	static vector<Link*> Links;
	int length;
	int loc_x;
	int loc_y;
	double link_number;
	double _a;
	double _alpha;
	double _d;
	double _theta;
	
	Link()
	{
		Links.push_back(this);
		link_number = Links.size() - 1;
	}

	Link(int origin_x, int origin_y, int l)
	{
		Links.push_back(this);
		length = l;
		link_number = Links.size() - 1;
	}

	void setDH(int a, int alpha, int d, int theta)
	{
		_alpha = alpha;
		_a = a;
		_d = d;
		_theta = theta;
	}

};


class Axis
{
public:
	
	static vector<Axis*> Axes;
	double axis_number;
	double orientation;
	int loc_x;
	int loc_y;
	mat rot_Z;
	
	Axis()
	{
		Axes.push_back(this);
		axis_number = Axes.size() - 1;
	}

	Axis(int origin_x, int origin_y, int l)
	{
		loc_x = origin_x;
		loc_y = origin_y;
		Axes.push_back(this);
		axis_number = Axes.size() - 1;
	}

	void rotate(double d)
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


};

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


/*int main()
{	
	/*int base_x = 250;
	int base_y = 0;
	Axis axis1();
	Axis axis2();
	Axis brush();
	Links link1(base_x, base_y, 150);
	link1.setDH(0,0,0,0); //Initialize DH, get theta from the gui
	Link link2;
	link2.setDH(0,150,0,0);
	Link link3;
	link3.setDH(0,100,0,0);
	return 0;
}*/
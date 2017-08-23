#include "Point.hpp"

Point::Point(double x, double y, double dx, double dy) : x(x), y(y), dx(dx), dy(dy)
{
}


Point::~Point()
{
}


bool Point::collides(Point &other)
{
	int ix = int(x);
	int iy = int(y);
	int ox = int(other.x);
	int oy = int(other.y);

	if(((ix <= ox && ox <= ix+P_SZ) && (iy <= oy && oy <= iy+P_SZ)) || ((ox <= ix && ix <= ox+P_SZ) && (oy <= iy && iy <= oy+P_SZ))){
		/* Fix */
		dx = -dx;
		dy = -dy;
		other.dx = -other.dx;
		other.dy = -other.dy;
		return true;
	}

	return false;
}


void Point::step()
{
	x += dx;
	y += dy;

	if(x < 1.0 || x >= W-1)
		dx = -dx;

	if(y < 1.0 || y >= H-1)
		dy = -dy;
}

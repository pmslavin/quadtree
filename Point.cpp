#include "Point.hpp"
#include "math.h"

Point::Point(double x, double y, double dx, double dy) : x(x), y(y), dx(dx), dy(dy)
{
}


Point::~Point()
{
}


bool Point::collides(Point &other)
{
	double xd = x - other.x;
	double yd = y - other.y;
	double hypot = sqrt(xd*xd+yd*yd);

	/* Fix */
	if(hypot <= 2.0*P_SZ){
		double cdrag = 0.9401;

		double lhspeed  = sqrt(dx*dx+dy*dy);
		double rhspeed  = sqrt(other.dx*other.dx+other.dy*other.dy);

		double theta = atan2(yd,xd) + M_PI_2;
//		double phi   = atan2(dy,dx) + M_PI_2;
//		double rho   = atan2(other.dy,other.dx) + M_PI_2;

		double av_x = sin(theta) * rhspeed;
		double av_y = cos(theta) * rhspeed;

		double av_angle = M_PI_2 - atan2(av_y, av_x);
		double av_len   = sqrt(av_x*av_x + av_y*av_y);

		dx = sin(av_angle)*av_len*cdrag;;
		dy = cos(av_angle)*av_len*cdrag;;

		av_x = sin(theta+M_PI) * lhspeed;
		av_y = cos(theta+M_PI) * lhspeed;

		av_angle = M_PI_2 - atan2(av_y, av_x);
		av_len   = sqrt(av_x*av_x + av_y*av_y);

		other.dx = sin(av_angle)*av_len*cdrag;;
		other.dy = cos(av_angle)*av_len*cdrag;;

		double intersect = 0.5*(2*P_SZ - hypot+1.0);
		x += sin(theta)*intersect;
		y -= cos(theta)*intersect;
		other.x -= sin(theta)*intersect;
		other.y += cos(theta)*intersect;

		return true;
	}

	return false;
}


void Point::step()
{
	x += dx;
	y += dy;

	dy += 0.04;

	if(x-P_SZ < 1 || x+P_SZ >= W)
		dx = -dx;

	if(y-P_SZ < 1 || y+P_SZ >= H)
		dy = -dy;
}

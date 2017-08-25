#ifndef __POINT__
#define __POINT__

#define W 1024
#define H 768

#define P_SZ 2

class Point{
public:
	Point(double=0.0, double=0.0, double=0.0, double=0.0);
	virtual ~Point();
	bool collides(Point &);
	double x;
	double y;
	double dx;
	double dy;
	void step();
private:

};

#endif

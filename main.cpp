#include "Frame.hpp"
#include "math.h"

double randFunc();
void populate_sine_rand(const unsigned int, std::vector<Point>&);
void populate_wheel(const unsigned int, std::vector<Point>&);

void (*populate)(const unsigned int, std::vector<Point>&);
const int fps = 30;
const unsigned int npoints = 1<<9;

void test_tree()
{
	initialise();
	std::vector<Point> points;

//	populate = &populate_sine_rand;
	populate = &populate_wheel;
	populate(npoints, points);
	wait();

	for(auto &p: points){
		drawPoint(p);
//		update();
	}

	update();
	wait();

	for(int t=0; t<8000; ++t){
		Quadtree steptree(nullptr, {0,0,1024,768});
		for(auto &p: points){
			drawPoint(p);
			steptree.insert(&p);
			p.step();
		}
		steptree.calcCollisions();
		update();
//		drawQuadtree(&steptree);
		pause(1000.0/fps);
		poll();
		clear();
	}
	wait();
}


void populate_sine_rand(const unsigned int npoints, std::vector<Point> &points)
{
	for(unsigned int i=0; i<npoints; ++i)
		points.push_back({i*W/(double)npoints, H/2+rand()%H/2*sin(2*i*M_PI/(npoints/2.0)), randFunc(), randFunc()});
}


void populate_wheel(const unsigned int npoints, std::vector<Point> &points)
{
	unsigned int t=1;
	int xorig = W/2;
	int yorig = H/2;
	int x,y;
	int rbase = 30;

	double r, theta;

	while(t<npoints){
		r = rbase + 0.8*yorig/(double)npoints*t + rand()%(int)(rbase*(2-t/(double)npoints));
		theta = 6*M_PI*t/npoints;
		x = xorig + r*cos(theta);
		y = yorig - r*sin(theta);

		points.push_back({(double)x, (double)y, 0.02*r*cos(theta+M_PI_2), -0.02*r*sin(theta+M_PI_2)});
		t++;
	}
}


double randFunc()
{
	return ((rand()|1)&15)*(drand48()-0.5);
}


int main(void)
{
	test_tree();
	return 0;
}

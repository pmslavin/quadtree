#include "Frame.hpp"
#include "math.h"

double randFunc();

int fps = 30;

void test_tree()
{
	initialise();
	std::vector<Point> points;

	for(int i=0; i<480; ++i)
		points.push_back({i*W/480.0, H/2+rand()%H/2*sin(2*i*M_PI/240.0), randFunc(), randFunc()});
//		points.push_back({(int)(i*W/200.0), (int)(H/2+rand()%H/2*sin(2*i*M_PI/100.0)), (double)6.0*(drand48()-0.5), (double)6.0*(drand48()-0.5)} );
//		points.push_back({(int)(i*W/200.0), (int)(H/2+H/2*sin(i*M_PI/100.0))});

/*
	points.push_back({400, 320});
	points.push_back({800, 320});
	points.push_back({400, 640});
	points.push_back({800, 640});
	points.push_back({420, 320});
	points.push_back({540, 100});
	points.push_back({800, 210});
*/
	wait();

	for(auto &p: points){
		drawPoint(p);
		update();
		pause(10);
	}

	wait();

	for(int t=0; t<8000; ++t){
		Quadtree steptree(nullptr, {0,0,1024,768});
		for(auto &p: points){
			steptree.insert(&p);
			drawPoint(p);
//			drawQuadtree(&steptree);
			p.step();
		}
		update();
		steptree.calcCollisions();
		pause(1000.0/fps);
		poll();
		clear();
	}
	wait();
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

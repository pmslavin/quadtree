#include "Frame.hpp"
#include "math.h"


void test_tree()
{
	Quadtree root(nullptr, {0,0,1024,768});

	initialise();
	std::vector<Point> points;

	for(int i=0; i<200; ++i)
		points.push_back({(int)(i*W/200.0), (int)(H/2+H/2*sin(i*M_PI/100.0))});

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
		root.insert(&p);
		drawPoint(p);
		drawQuadtree(&root);
		update();
		pause(100);
	}

	root.report();
	wait();
}


int main(void)
{
	test_tree();
	return 0;
}

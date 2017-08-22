#ifndef __FRAME__
#define __FRAME__

#include "Quadtree.hpp"

#define W 1024
#define H 768

void update();
void initialise();
void drawQuadtree(Quadtree *);
void pause(unsigned int);
void drawPoint(Point);
void wait();

#endif

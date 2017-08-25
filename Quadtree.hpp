#ifndef __QUADTREE__
#define __QUADTREE__

#include <array>
#include <vector>
#include "Rect.hpp"
#include "Point.hpp"

#define MAX_ELEMS 5

class Quadtree{

public:
	Quadtree(Quadtree *, Rect={0,0,0,0});
	Quadtree();
	virtual ~Quadtree();
	void split();
	Quadtree *region(Point *);
	Quadtree *insert(Point *);
	void clear();
	void report(unsigned int=0);
	Quadtree *getParent();
	const Rect getRect() const;
	unsigned int calcCollisions();
	friend void drawQuadtree(Quadtree *);
private:
	Quadtree *parent;
	Rect bounds;
	std::array<Quadtree,4> *nodes;
	std::vector<Point *> points;
};


#endif

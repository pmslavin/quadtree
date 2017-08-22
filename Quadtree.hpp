#ifndef __QUADTREE__
#define __QUADTREE__

#include <array>
#include <vector>
#include "Rect.hpp"

#define MAX_ELEMS 1
#define MAX_DEPTH 5

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
	friend void drawQuadtree(Quadtree *);
private:
	std::array<Quadtree,4> *nodes;
	Quadtree *parent;
	unsigned int depth;
	Rect bounds;
	std::vector<Point *> points;
};


#endif

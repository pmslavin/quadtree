#ifndef __QUADTREE__
#define __QUADTREE__

#include <array>
#include "Rect.hpp"

#define MAX_ELEMS  1
#define MAX_DEPTH 5

class Quadtree{

public:
	Quadtree(Quadtree *, Rect={0,0,0,0});
	Quadtree(unsigned int, Rect={0,0,0,0});
	Quadtree();
	virtual ~Quadtree();
	void split();
	Quadtree *region(int, int);
	void insert(int, int);
	void clear();
	void report(unsigned int=0);
	Quadtree *getParent();

private:
	Quadtree *parent;
	unsigned int depth;
	Rect bounds;
	std::array<Quadtree,4> *nodes;
};



#endif

#include "Quadtree.hpp"

int main(void)
{
	Quadtree q;
	q.report();
	q.split();
	q.report();
	q.clear();
	q.report();
	return 0;
}

#include <iostream>
#include "Quadtree.hpp"

Quadtree::Quadtree(unsigned int d, Rect r)
{
	depth  = d;
	bounds = r;
}


Quadtree::Quadtree()
{
	bounds = {0,0,0,0};
	nodes  = nullptr;
	parent = nullptr;
}


Quadtree::~Quadtree()
{
	if(nodes)
		clear();
	if(parent)
		parent = nullptr;
}


void Quadtree::split()
{
	nodes = new std::array<Quadtree,4>;
}


Quadtree *Quadtree::region(int x, int y)
{
	(void)x;
	(void)y;
	return nullptr;
}

void insert(int x, int y)
{
	(void)x;
	(void)y;
}


void Quadtree::clear()
{
	if(!nodes)
		return;

	for(auto &n: *nodes)
		n.clear();

	delete nodes;
	nodes = nullptr;
}


void Quadtree::report(unsigned int depth)
{
	std::string indent;
	for(unsigned int i=0; i<depth; ++i)
		indent.push_back('\t');

	std::cout << indent << "Quadtree at: " << this << std::endl;
	std::cout << indent << "\tbounds.{x,y}: " << bounds.x << "," << bounds.y << std::endl;
	std::cout << indent << "\tbounds.{w,h}: " << bounds.w << "," << bounds.w << std::endl;
	std::cout << indent << "\tnodes at: " << nodes << std::endl;

	if(nodes)
		for(auto &n: *nodes)
			n.report(depth+1);
}

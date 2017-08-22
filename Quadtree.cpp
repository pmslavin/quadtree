#include <iostream>
#include "Quadtree.hpp"

Quadtree::Quadtree(Quadtree *parent, Rect r)
{
	this->parent = parent;
	bounds = r;
	nodes = nullptr;
}


//Quadtree::Quadtree(unsigned int d, Rect r)
//{
//	depth = d;
//	bounds = r;
//}


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
	nodes = new std::array<Quadtree,4>{{ {this, {bounds.x,bounds.y,bounds.w/2,bounds.h/2}},
										 {this, {bounds.x+bounds.w/2,bounds.y,bounds.w/2,bounds.h/2}},
										 {this, {bounds.x+bounds.w/2,bounds.y+bounds.h/2,bounds.w/2,bounds.h/2}},
										 {this, {bounds.x,bounds.y+bounds.h/2,bounds.w/2,bounds.h/2}},
									  }};
}


Quadtree *Quadtree::region(Point *p)
{
	if(p->x >= bounds.x && p->x < bounds.x+bounds.w && p->y >= bounds.y && p->y < bounds.y+bounds.h)
		return this;

	return nullptr;
}


Quadtree *Quadtree::insert(Point *p)
{
	if(points.size() < MAX_ELEMS && !nodes){
		points.push_back(p);
		return this;
	}

	if(!nodes){
		split();
		for(size_t i=0; i<points.size(); ++i){
			for(auto &n: *nodes){
				if(n.region(points[i])){
					n.insert(points[i]);
					points.erase(points.begin()+i, points.begin()+i+1);
				}
			}

		}
	}


	for(auto &n: *nodes){
		if(n.region(p))
			n.insert(p);
	}

	return nullptr;
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
	std::cout << indent << "\tbounds.{w,h}: " << bounds.w << "," << bounds.h << std::endl;
	std::cout << indent << "\tparent: " << parent << std::endl;
	std::cout << indent << "\tnodes: " << nodes << std::endl;

	for(auto &p: points)
		std::cout << indent << "\t\tpoint.{x,y}: " << p->x << "," << p->y << std::endl;

	if(nodes)
		for(auto &n: *nodes)
			n.report(depth+1);
}


Quadtree *Quadtree::getParent()
{
	return parent;
}


const Rect Quadtree::getRect() const
{
	return bounds;
}

#include "SDL2/SDL.h"
#include "Frame.hpp"


SDL_Window 	 *window   = nullptr;
SDL_Renderer *renderer = nullptr;
SDL_Surface	 *surface  = nullptr;
SDL_Texture	 *texture  = nullptr;


void initialise()
{
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS);
	window   = SDL_CreateWindow("Quadtree", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, W, H, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture  = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, W, H);
	surface  = SDL_CreateRGBSurface(0, W, H, 32, 0, 0, 0, 0);

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
	update();
}


void update()
{
	SDL_RenderPresent(renderer);
}


void drawQuadtree(Quadtree *q)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_Rect sr	= {q->bounds.x, q->bounds.y, q->bounds.w, q->bounds.h};
	SDL_RenderDrawRect(renderer, &sr);

	if(q->nodes){
		for(auto &n: *(q->nodes))
			drawQuadtree(&n);
	}

}

void drawPoint(Point p)
{
	SDL_SetRenderDrawColor(renderer, 0x28, 0xcc, 0x22, 0xFF);
	SDL_RenderDrawPoint(renderer, p.x, p.y);
	SDL_RenderDrawPoint(renderer, p.x+1, p.y);
	SDL_RenderDrawPoint(renderer, p.x, p.y+1);
	SDL_RenderDrawPoint(renderer, p.x+1, p.y+1);
/* Radius 4 circle */
/*
	SDL_RenderDrawLine(renderer, p.x-1, p.y-3, p.x+2, p.y-3);
	SDL_RenderDrawLine(renderer, p.x-2, p.y-2, p.x+3, p.y-2);

	SDL_RenderDrawLine(renderer, p.x-3, p.y-1, p.x+4, p.y-1);
	SDL_RenderDrawLine(renderer, p.x-3, p.y,   p.x+4, p.y);
	SDL_RenderDrawLine(renderer, p.x-3, p.y+1, p.x+4, p.y+1);

	SDL_RenderDrawLine(renderer, p.x-2, p.y+2, p.x+3, p.y+2);
	SDL_RenderDrawLine(renderer, p.x-1, p.y+3, p.x+2, p.y+3);
*/
}


void clear()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);
}


void pause(unsigned int t)
{
	SDL_Delay(t);
}


void poll()
{
	SDL_Event e;
	if(SDL_PollEvent(&e))
        if(e.type == SDL_KEYDOWN)
			exit(0);
}


void wait()
{
	SDL_Event e;
    while(SDL_WaitEvent(&e))
        if(e.type == SDL_KEYDOWN)
            break;
}

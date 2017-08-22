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

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	update();
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}


void update()
{
	SDL_RenderPresent(renderer);
}


void drawQuadtree(Quadtree *q)
{
	SDL_Rect sr	= {q->bounds.x, q->bounds.y, q->bounds.w, q->bounds.h};
	SDL_RenderDrawRect(renderer, &sr);

	if(q->nodes){
		for(auto &n: *(q->nodes))
			drawQuadtree(&n);
	}

}

void drawPoint(Point p)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawPoint(renderer, p.x,   p.y);
	SDL_RenderDrawPoint(renderer, p.x+1, p.y);
	SDL_RenderDrawPoint(renderer, p.x,   p.y+1);
	SDL_RenderDrawPoint(renderer, p.x+1, p.y+1);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}


void pause(unsigned int t)
{
	SDL_Delay(t);
}


void wait()
{
	SDL_Event e;
    while(SDL_WaitEvent(&e))
        if(e.type == SDL_KEYDOWN)
            break;
}

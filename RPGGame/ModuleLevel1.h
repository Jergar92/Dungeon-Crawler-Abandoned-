#ifndef __MODULELEVEL1_H__
#define __MODULELEVEL1_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleLevel1 : public Module
{
public:
	ModuleLevel1();
	~ModuleLevel1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int map[10][10];
	bool islevel3;

	SDL_Texture* graphics = nullptr;

	//Parallel Walls
	SDL_Rect lvl1_parallel_wall;
	SDL_Rect lvl2_parallel_wall;
	SDL_Rect lvl3_parallel_wall;
	SDL_Rect lvl4_parallel_wall;

	//Front Walls
	SDL_Rect lvl2_front_wall;
	SDL_Rect lvl3_front_wall;
	SDL_Rect lvl4_front_wall;

	//Large Front Walls
	SDL_Rect lvl2_large_front_wall;
	SDL_Rect lvl3_large_front_wall;
	SDL_Rect lvl4_large_front_wall;

	//Close Wall
	SDL_Rect lvl1_close_wall;
};

#endif
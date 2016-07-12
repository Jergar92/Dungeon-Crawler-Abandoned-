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

	SDL_Texture* g_corridor = nullptr;
	SDL_Texture* g_corridorv1 = nullptr;
	SDL_Texture* g_directions = nullptr;
	SDL_Texture* g_directionsv1 = nullptr;
	SDL_Texture* g_background1 = nullptr;
	SDL_Texture* g_wall = nullptr;
	SDL_Texture* g_exit = nullptr;

	SDL_Rect corridor;
	SDL_Rect corridorv1;
	SDL_Rect directions;
	SDL_Rect directionsv1;
	SDL_Rect background1;
	SDL_Rect exit;
	SDL_Rect wall;

};

#endif
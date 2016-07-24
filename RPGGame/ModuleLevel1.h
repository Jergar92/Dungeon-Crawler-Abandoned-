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

	SDL_Rect lvl1_wall;
	SDL_Rect corridorv1;
	SDL_Rect directions;
	SDL_Rect directionsv1;
	SDL_Rect background1;
	SDL_Rect exit;
	SDL_Rect wall;

};

#endif
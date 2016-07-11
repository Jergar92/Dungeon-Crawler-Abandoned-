#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

enum direction{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* g_corridor = nullptr;
	SDL_Texture* g_corridorv1 = nullptr;
	SDL_Texture* g_directions = nullptr;
	SDL_Texture* g_directionsv1 = nullptr;
	SDL_Texture* g_background1 = nullptr;
	SDL_Texture* direct = nullptr;
	SDL_Texture* g_exit = nullptr;

	iPoint position;
	SDL_Rect corridor;
	SDL_Rect corridorv1;
	SDL_Rect directions;
	SDL_Rect directionsv1;
	SDL_Rect background1;
	SDL_Rect test;
	SDL_Rect exit;
	SDL_Rect compass;

//	int direction;//1 North, 2 West, 3 South, 4 East
	direction dir;
//?	int map_player[10][10];
	int room_tile;

	void ChangeTile(int);
};

#endif
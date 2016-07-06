#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* g_pasillo = nullptr;
	SDL_Texture* g_pasillov1 = nullptr;
	SDL_Texture* g_direciones = nullptr;
	SDL_Texture* g_direcionesv1 = nullptr;
	SDL_Texture* g_fondo1 = nullptr;
	SDL_Texture* g_fondo2 = nullptr;
	SDL_Texture* g_fondo3 = nullptr;
	SDL_Texture* direct = nullptr;
	iPoint position;
	SDL_Rect pasillo;
	SDL_Rect pasillov1;
	SDL_Rect direciones;
	SDL_Rect direcionesv1;
	SDL_Rect fondo1;
	SDL_Rect fondo2;
	SDL_Rect fondo3;
	SDL_Rect test;
	SDL_Rect brujula;
	int direction;//1 North, 2 West, 3 South, 4 East
	int map_player[10][10];
	int num;
};

#endif
#ifndef __MODULE_MINIGAMES_H__
#define __MODULE_MINIGAMES_H__

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleMinigames : public Module
{
public:
	ModuleMinigames();
	~ModuleMinigames();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* g_numbers = nullptr;
	SDL_Texture* graphics_info = nullptr;


	//numbers

	SDL_Rect numbers;
	//Level 1 PI
	SDL_Rect puzzle_lvl1_interact;
	SDL_Rect puzzle_lvl1_info;
	SDL_Rect Botton_1;
	SDL_Rect Botton_2;
	SDL_Rect Botton_3;
	SDL_Rect Botton_4;
	SDL_Rect Botton_5;

	bool puzzles_complets[4];
	int num[5];
	void three_line_game();
	void numbers_game();
	void simon_game();
	void puzzle_game();
	/*char mat[3][3];
	void Iniciar_tablero(char mat[3][3]);
	void Tablero(const char mat[3][3]);
	void Yo_tirada(char mat[3][3]);
	void Pc_tirada(char mat[3][3]);
	void funciones(char mat[3][3]);*/


	//Textures
};

#endif
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
	SDL_Texture* Puzzle = nullptr;
	SDL_Texture* graphics_simon = nullptr;

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
	void numbers_game();

	//Level 2 simon
	SDL_Rect puzzle_lvl2_info;
	SDL_Rect puzzle_lvl2_interact;
	SDL_Rect yellow_color;
	SDL_Rect green_color;
	SDL_Rect red_color;
	SDL_Rect pink_color;
	SDL_Rect blue_color;
	SDL_Rect mark;
	uint round;
	uint player_round;
	uint last_round;
	uint mark_time;
	uint last_simon_time;
	uint current_simon_time;
	bool new_wave;
	uint sequence[25];
	uint player_sequence[25];


	//Level 3 Puzzle
	SDL_Rect puzzle_1;
	SDL_Rect puzzle_2;
	SDL_Rect puzzle_3;
	SDL_Rect puzzle_4;
	SDL_Rect puzzle_5;
	SDL_Rect puzzle_6;
	SDL_Rect puzzle_7;
	SDL_Rect puzzle_8;
	SDL_Rect puzzle_9;
	void puzzle_game();
	int num_puzzle[9];
	bool isenable[9];
	int swap_1 = 0;
	int swap_2 = 0;


	void three_line_game();
	void simon_game();

	char mat[3][3];
	void Iniciar_tablero(char mat[3][3]);
	void Tablero(const char mat[3][3]);
	void Yo_tirada(char mat[3][3]);
	void Pc_tirada(char mat[3][3]);
	//void funciones(char mat[3][3]);
	int Ganador(const char mat[3][3]);

	//Textures
};

#endif
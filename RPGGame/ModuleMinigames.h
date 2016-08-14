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

	void three_line_game();
	void numbers_game();
	void simon_game();
	void puzzle_game();

	//Textures
};

#endif
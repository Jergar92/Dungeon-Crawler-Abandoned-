#ifndef __MODULECOMMONLEVELS_H__
#define __MODULECOMMONLEVELS_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"

struct SDL_Texture;

class ModuleCommonLevels : public Module
{
public:
	ModuleCommonLevels();
	~ModuleCommonLevels();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* Keys_wasd = nullptr;

	SDL_Rect Key_w;
	SDL_Rect Key_a;
	SDL_Rect Key_s;
	SDL_Rect Key_d;
};

#endif //__MODULECOMMONLEVELS_H__
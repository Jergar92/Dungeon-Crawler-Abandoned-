#ifndef _GUI_
#define _GUI_
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleGui : public Module
{
public:
	ModuleGui();
	~ModuleGui();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
};


#endif //__MODULEUI_H__
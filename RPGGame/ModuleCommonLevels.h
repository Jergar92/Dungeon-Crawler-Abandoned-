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

	bool CheckButton(const SDL_Rect* button, int x, int y) const;

	//sprites
	SDL_Texture* Keys_wasd = nullptr;
	SDL_Rect Key_w;
	SDL_Rect Key_a;
	SDL_Rect Key_s;
	SDL_Rect Key_d;

	//place in screen
	SDL_Rect Rect_W;
	SDL_Rect Rect_A;
	SDL_Rect Rect_S;
	SDL_Rect Rect_D;

	bool click_W = false;
	bool click_A = false;
	bool click_S = false;
	bool click_D = false;
};

#endif //__MODULECOMMONLEVELS_H__
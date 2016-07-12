#ifndef __MODULEUI_H__
#define __MODULEUI_H__

#include "Module.h"
#include "Globals.h"
#include "Application.h"

struct SDL_Texture;
enum movementState { NONE, PRES_Q,PRES_W,PRES_E,PRES_A,PRES_S,PRES_D };
class ModuleUI : public Module
{
public:
	ModuleUI();
	~ModuleUI();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	bool CheckButton(const SDL_Rect* button, int x, int y) const;

	//sprites
	SDL_Texture* Keys_wasd = nullptr;
	SDL_Rect Key_w_dwn;
	SDL_Rect Key_q_dwn;
	SDL_Rect Key_a_dwn;
	SDL_Rect Key_e_dwn;
	SDL_Rect Key_s_dwn;
	SDL_Rect Key_d_dwn;
	SDL_Rect Key_w_up;
	SDL_Rect Key_q_up;
	SDL_Rect Key_a_up;
	SDL_Rect Key_e_up;
	SDL_Rect Key_s_up;
	SDL_Rect Key_d_up;
	//place in screen
	SDL_Rect Rect_Q;
	SDL_Rect Rect_W;
	SDL_Rect Rect_E;
	SDL_Rect Rect_A;
	SDL_Rect Rect_S;
	SDL_Rect Rect_D;
	enum movementState myMovementState;
	bool click_Q = false;
	bool click_W = false;
	bool click_E = false;
	bool click_A = false;
	bool click_S = false;
	bool click_D = false;
	bool movement = false;
};

#endif //__MODULEUI_H__
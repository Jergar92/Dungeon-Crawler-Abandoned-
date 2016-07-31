#ifndef _GUI_MOVEMENT_
#define _GUI_MOVEMENT_

#include "Module.h"
#include "Globals.h"
#include "Application.h"
#define MAX_BUTTON 10

struct SDL_Texture;
enum movementState { NONE, PRES_Q,PRES_W,PRES_E,PRES_A,PRES_S,PRES_D };
/*
enum ButtonType{ MOVEMENT_BUTTON};

struct Button{
private:
	SDL_Rect* sprite;
	ButtonType type;
	Module* callback = nullptr;
public:
	SDL_Rect rect;

	Button(ButtonType type, Module* callback = nullptr) : type(type),callback(callback)
	{}
	virtual bool CheckCollision(const Button* c) const = 0;
	virtual void SetPos(int x, int y) = 0;
};


struct ButtonRect : public Button
{
	ButtonRect(SDL_Rect rectangle, ButtonType type, Module* callback = nullptr) : Button(type, callback)
	{
		rect = rectangle;
	}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const Button* c) const;
};

*/

class GUI_Movement : public Module
{
public:
	GUI_Movement();
	~GUI_Movement();

	bool Start();
	update_status Update();
	bool CleanUp();
	void Retexture();
public:
	//sprites
	SDL_Texture* Keys_wasd = nullptr;
	SDL_Rect Key_w_dwn;
	SDL_Rect Key_q_dwn;
	SDL_Rect Key_a_dwn;
	SDL_Rect Key_e_dwn;
	SDL_Rect Key_s_dwn;
	SDL_Rect Key_d_dwn;
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
	//Button* button[MAX_BUTTON];
	bool CheckButton(const SDL_Rect* button, int x, int y) const;

};


#endif //__MODULEUI_H__
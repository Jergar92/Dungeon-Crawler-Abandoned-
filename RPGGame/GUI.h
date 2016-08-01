#ifndef _GUI_
#define _GUI_
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct Circle{
public:
	Circle(int radius, int positionX, int positionY) :radius(radius), positionX(positionX), positionY(positionY)
	{}
	int radius;
	int positionX;
	int positionY;
};
class ModuleGui : public Module
{
public:
	ModuleGui();
	~ModuleGui();

	bool Start();
	update_status Update();
	bool CleanUp();
	bool CheckButton(const SDL_Rect* button, int x, int y) const;
	bool CheckButtonCircle(const Circle* button, int x, int y) const;

public:
	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
};


#endif //__MODULEUI_H__
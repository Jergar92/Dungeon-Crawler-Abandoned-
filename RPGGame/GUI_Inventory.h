#include "Module.h"
#include "Globals.h"
#include "Application.h"
struct SDL_Texture;
enum InventoryActive { ON, OFF };
struct Character_Icon{
public:
	Character_Icon();
	SDL_Rect Character_alive;
	SDL_Rect Character_injured;
	SDL_Rect Character_dead;

	SDL_Rect Character_life;
	SDL_Rect Character_mana;

	enum CharacterState CurrentState;
};
struct Inventory{
public:
	Inventory();

	SDL_Rect Arrow_right;
	SDL_Rect Arrow_left;
	SDL_Rect Exit;

	enum CharacterState CurrentState;
};
class GUI_Inventory : public Module
{
public:
	GUI_Inventory();
	~GUI_Inventory();
	InventoryActive InvectoryIs;
	SDL_Rect Player1;
	SDL_Rect Player2;
	SDL_Rect Player3;
	SDL_Rect Player4;
	bool Start();
	update_status Update();
	bool CleanUp();
	void Retexture();
public:

	bool CheckButton(const SDL_Rect* button, int x, int y) const;

	//sprites

	SDL_Texture* Characters_sprites = nullptr;
	SDL_Texture* Inventory = nullptr;
	SDL_Rect Inventory_background;

	enum CharacterState currenState;



};

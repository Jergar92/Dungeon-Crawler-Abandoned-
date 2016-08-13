#include "Module.h"
#include "Globals.h"
#include "Application.h"

struct SDL_Texture;
#define MAX_ROWS 3
#define MAX_COLUMNS 3
#define MAX_SLOTS 12
enum InventoryActive { ON, OFF };
enum currentCharracter{ CHARACTER_ONE, CHARACTER_TWO, CHARACTER_THREE, CHARACTER_FOUR, NO_CHARACTER };
struct Character_Icon{
public:
	Character_Icon();
	SDL_Rect Sloot[12];
};
struct Inventory{
public:
	Inventory();



};
class GUI_Inventory : public Module
{
public:
	GUI_Inventory();
	~GUI_Inventory();
	InventoryActive InventoryIs;
	currentCharracter InventoryCharacter;
	bool Start();
	update_status Update();
	bool CleanUp();
	void Retexture();
public:
	//sprites
	Inventory* Inventory_character[4];
	SDL_Texture* Characters_sprites = nullptr;
	SDL_Texture* Inventory = nullptr;
	SDL_Rect Inventory_background;
	Character_Icon slots;
	SDL_Rect Player1;
	SDL_Rect Player2;
	SDL_Rect Player3;
	SDL_Rect Player4;
	SDL_Rect Arrow_right;
	SDL_Rect Arrow_left;
	SDL_Rect Exit;
	bool itemSelected(currentCharracter InventoryCharacter);
	bool isOcuped(currentCharracter InventoryCharacter,int slot);
	void changeSlotValues();
};

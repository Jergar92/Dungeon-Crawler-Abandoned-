#include "Module.h"
#include "Globals.h"
#include "Application.h"
#define MAX_CHARACTERS 4

struct SDL_Texture;
enum CharacterState {ALIVE, DEAD, INJURED };
struct Character{
public:
	Character();
	SDL_Rect Atack;
	SDL_Rect Atack_cooldown;

	SDL_Rect Special_Atack;
	SDL_Rect Special_Atack_cooldown;

	SDL_Rect Character_alive;
	SDL_Rect Character_injured;
	SDL_Rect Character_dead;

	SDL_Rect Character_life;
	SDL_Rect Character_mana;

	SDL_Rect Button_Atack;
	SDL_Rect Button_Special_Atack;
	enum CharacterState CurrentState;
};
class GUI_Character : public Module
{
public:
	GUI_Character();
	~GUI_Character();
	bool Start();
	update_status Update();
	bool CleanUp();
	void Retexture();
public:
	SDL_Texture* Characters_sprites = nullptr;
	enum CharacterState currenState;
	
	Character* character[MAX_CHARACTERS];

};

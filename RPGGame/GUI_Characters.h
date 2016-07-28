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

	bool CheckButton(const SDL_Rect* button, int x, int y) const;

	//sprites
	SDL_Texture* Characters_sprites = nullptr;
	
	//Character 1
	SDL_Rect Atack_one_place;
	SDL_Rect Special_Atack_one_place;
	SDL_Rect Character_one_place;
	SDL_Rect Character_one_life_place;
	SDL_Rect Character_one_mana_place;
	//Character 2
	SDL_Rect Atack_two_place;
	SDL_Rect Special_Atack_two_place;
	SDL_Rect Character_two_place;
	SDL_Rect Character_two_life_place;
	SDL_Rect Character_two_mana_place;
	//Character 3
	SDL_Rect Atack_three_place;
	SDL_Rect Special_Atack_three_place;
	SDL_Rect Character_three_place;
	SDL_Rect Character_three_life_place;
	SDL_Rect Character_three_mana_place;
	//Character 4
	SDL_Rect Atack_four_place;
	SDL_Rect Special_Atack_four_place;
	SDL_Rect Character_four_place;
	SDL_Rect Character_four_life_place;
	SDL_Rect Character_four_mana_place;
	enum CharacterState currenState;
	
	Character* character[MAX_CHARACTERS];

};

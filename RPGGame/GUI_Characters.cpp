#include "SDL/include/SDL.h"
#include "GUI_Characters.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

GUI_Character::GUI_Character()
{
	int i = 0;

	Character* one = new Character();
	one->Character_alive = { 0, 0, 100, 100 };
	one->Character_injured = { 100, 0, 100, 100 };
	one->Character_dead = { 200, 0, 100, 100 };
	one->Character_life = { 396, 0, 96, 12 };
	one->Character_mana = { 396, 12, 96, 12 };
	one->Atack = { 300, 0, 48, 41 };
	one->Atack_cooldown = { 300, 41, 48, 41 };
	one->Special_Atack = { 349, 0, 47, 41 };
	one->Special_Atack_cooldown = { 349, 41, 47, 41 };
	one->CurrentState = ALIVE;
	character[i++] = one;

	Character* two = new Character();
	two->Character_alive = { 0, 100, 100, 100 };
	two->Character_injured = { 100, 100, 100, 100 };
	two->Character_dead = { 200, 100, 100, 100 };
	two->Character_life = { 396, 0, 96, 12 };
	two->Character_mana = { 396, 12, 96, 12 };
	two->Atack = { 300, 100, 48, 41 };
	two->Atack_cooldown = { 300, 141, 48, 41 };
	two->Special_Atack = { 349, 100, 47, 41 };
	two->Special_Atack_cooldown = { 349, 141, 47, 41 };
	two->CurrentState = ALIVE;
	character[i++] = two;

	Character* three = new Character();
	three->Character_alive = { 0, 200, 100, 100 };
	three->Character_injured = { 100, 200, 100, 100 };
	three->Character_dead = { 200, 200, 100, 100 };
	three->Character_life = { 396, 0, 96, 12 };
	three->Character_mana = { 396, 12, 96, 12 };
	three->Atack = { 300, 200, 48, 41 };
	three->Atack_cooldown = { 300, 241, 48, 41 };
	three->Special_Atack = { 349, 200, 47, 41 };
	three->Special_Atack_cooldown = { 349, 241, 47, 41 };
	three->CurrentState = ALIVE;

	character[i++] = three;

	Character* four = new Character();
	four->Character_alive = { 0, 300, 100, 100 };
	four->Character_injured = { 100, 300, 100, 100 };
	four->Character_dead = { 200, 300, 100, 100 };
	four->Character_life = { 396, 0, 96, 12 };
	four->Character_mana = { 396, 12, 96, 12 };
	four->Atack = { 300, 300, 48, 41 };
	four->Atack_cooldown = { 300, 341, 48, 41 };
	four->Special_Atack = { 349, 300, 47, 41 };
	four->Special_Atack_cooldown = { 349, 341, 47, 41 };
	four->CurrentState = ALIVE;

	character[i++] = four;

}
GUI_Character::~GUI_Character()
{}

bool GUI_Character::Start()
{
	Characters_sprites = App->texture->Load("CharacterSprites.png");
	/*
	Character_one_place = { 606, 14, 88, 88 };
	Character_one_life_place = { 708, 14, 88, 16 };
	Character_one_mana_place = { 708, 37, 88, 16 };
	Atack_one_place = { 708, 60, 42, 42 };
	Special_Atack_one_place = { 754, 60, 42, 42 };

	Character_two_place = { 606, 116, 88, 88 };
	Character_two_life_place = { 708, 116, 88, 16 };
	Character_two_mana_place = { 708, 139, 88, 16 };
	Atack_two_place = { 708, 162, 42, 42 };
	Special_Atack_two_place = { 754, 162, 42, 42 };

	Character_three_place = { 606, 218, 88, 88 };
	Character_three_life_place = { 708, 218, 88, 16 };
	Character_three_mana_place = { 708, 241, 88, 16 };
	Atack_three_place = { 708, 264, 42, 42 };
	Special_Atack_three_place = { 754, 264, 42, 42 };

	Character_four_place = { 606, 320, 88, 88 };
	Character_four_life_place = { 708, 320, 88, 16 };
	Character_four_mana_place = { 708, 343, 88, 16 };
	Atack_four_place = { 708, 366, 42, 42 };
	Special_Atack_four_place = { 754, 366, 42, 42 };
	*/
	bool ret = true;
	LOG("Loading frontground assets");
	return ret;
}

bool GUI_Character::CleanUp()
{

	App->texture->Unload(Characters_sprites);
	for (uint i = 0; i < MAX_CHARACTERS; ++i)
	{
		if (character[i] != nullptr)
		{
			delete character[i];
			character[i] = nullptr;
		}
	}
	LOG("Unloading Common Levels stuff");
	return true;
}
void GUI_Character::Retexture(){
	for (int i = 0; i < MAX_CHARACTERS; i++){
		//Character Icon
		if (character[i]->CurrentState == ALIVE){
			App->render->Blit(Characters_sprites, 600 * SCREEN_SIZE, (100* i) * SCREEN_SIZE, &character[i]->Character_alive);
		}
		else if (character[i]->CurrentState == INJURED){
			App->render->Blit(Characters_sprites, 600 * SCREEN_SIZE, (100 * i) * SCREEN_SIZE, &character[i]->Character_injured);

		}
		else{
			App->render->Blit(Characters_sprites, 600 * SCREEN_SIZE, (100 * i) * SCREEN_SIZE, &character[i]->Character_dead);
		}
		//Life/Mana Bar
		 
		App->render->Blit(Characters_sprites, 693 * SCREEN_SIZE, (10 + (100 * i)) * SCREEN_SIZE, &character[i]->Character_life);
		App->render->Blit(Characters_sprites, 693 * SCREEN_SIZE, (28 + (100 * i)) * SCREEN_SIZE, &character[i]->Character_mana);
		
		//Atack//Special Atack

		App->render->Blit(Characters_sprites, 693 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Atack);
		App->render->Blit(Characters_sprites, 742 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Special_Atack);
	}


}
update_status GUI_Character::Update()
{
	if (App->player->IsEnabled()==true){
		for (int i = 0; i < MAX_CHARACTERS; i++){
			if (App->player->formation[i]->hp < (App->player->formation[i]->max_hp) / 2 && (App->player->formation[i]->hp > 0)){
				character[i]->CurrentState = INJURED;
			}
			else if (App->player->formation[i]->hp <=0){
				character[i]->CurrentState = DEAD;
			}
			else{
				character[i]->CurrentState = ALIVE;
			}
		}
		for (int i = 0; i < MAX_CHARACTERS; i++){
			character[i]->Character_life = { 396, 0, (App->player->formation[i]->hp * 96) / App->player->formation[i]->max_hp, 12 };
			character[i]->Character_mana = { 396, 12, (App->player->formation[i]->mp * 96) / App->player->formation[i]->max_mp, 12 };
		}
		SDL_Event Event;
		bool running = true;
		Retexture();
		
	}
	return UPDATE_CONTINUE;
}

bool GUI_Character::CheckButton(const SDL_Rect* button, int x, int y) const
{
	return (x< button->x*SCREEN_SIZE + button->w*SCREEN_SIZE  && x >= button->x*SCREEN_SIZE &&
		y < button->y*SCREEN_SIZE + button->h*SCREEN_SIZE  && y >= button->y*SCREEN_SIZE);
}

Character::Character(){

}
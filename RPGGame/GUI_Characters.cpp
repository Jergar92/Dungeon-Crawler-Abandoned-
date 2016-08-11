#include "SDL/include/SDL.h"
#include "GUI_Characters.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "Gui.h"
#include "ModuleInput.h"
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
	one->Button_Atack = { 693, 47, 47, 41 };
	one->Button_Special_Atack = { 742, 47, 47, 41 }; 
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
	two->Button_Atack = { 693, 147, 47, 41 };
	two->Button_Special_Atack = { 742, 147, 47, 41 };
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
	three->Button_Atack = { 693, 247, 47, 41 };
	three->Button_Special_Atack = { 742, 247, 47, 41 };
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
	four->Button_Atack = { 693, 347, 47, 41 };
	four->Button_Special_Atack = { 742, 347, 47, 41 };
	four->CurrentState = ALIVE;

	character[i++] = four;

}
GUI_Character::~GUI_Character()
{}

bool GUI_Character::Start()
{
	Characters_sprites = App->texture->Load("CharacterSprites.png");
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
		//Atack
		if (App->player->formation[i]->MyAttack==READY)
			App->render->Blit(Characters_sprites, 693 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Atack);
		else
			App->render->Blit(Characters_sprites, 693 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Atack_cooldown);
		//Special Atack
		if (App->player->formation[i]->MySpecialAttack == READY)
			App->render->Blit(Characters_sprites, 742 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Special_Atack);
		else
			App->render->Blit(Characters_sprites, 742 * SCREEN_SIZE, (47 + (100 * i)) * SCREEN_SIZE, &character[i]->Special_Atack_cooldown);

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
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			for (int i = 0; i < MAX_CHARACTERS; i++){
				if (App->gui->CheckButton(&character[i]->Button_Atack, App->input->mouse_x, App->input->mouse_y)){
					//Attack Function
					App->player->formation[i]->MyAttack = COOLDOWN;
					Retexture();
				}
				else if (App->gui->CheckButton(&character[i]->Button_Special_Atack, App->input->mouse_x, App->input->mouse_y)){
					//Attack Function
					App->player->formation[i]->MySpecialAttack = COOLDOWN;
					Retexture();
				}
			}
		}
		bool running = true;
		Retexture();
		
	}
	return UPDATE_CONTINUE;
}


Character::Character(){

}
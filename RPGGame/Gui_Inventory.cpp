#include "SDL/include/SDL.h"
#include "GUI.h"
#include "GUI_Inventory.h"
#include "ModuleCollider.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"
GUI_Inventory::GUI_Inventory()
{

}
GUI_Inventory::~GUI_Inventory()
{}

bool GUI_Inventory::Start()
{
	Inventory = App->texture->Load("Inventory.png");
	InventoryIs = OFF;
	InventoryCharacter = NO_CHARACTER;
	Player1 = { 600, 0, 80, 80 };
	Player2 = { 450, 0, 80, 80 };
	Inventory_background = { 0, 0, 306, 401 };
	bool ret = true;
	LOG("Loading frontground assets");
	return ret;
}

bool GUI_Inventory::CleanUp()
{

	App->texture->Unload(Inventory);

	LOG("Unloading Common Levels stuff");
	return true;
}
void GUI_Inventory::Retexture(){
	if (InventoryIs != OFF){
		App->render->Blit(Inventory, 490 * SCREEN_SIZE, 0 * SCREEN_SIZE, &Inventory_background);
		switch (InventoryCharacter)
		{
		case CHARACTER_ONE:
		case CHARACTER_TWO:
		case CHARACTER_THREE:
		case CHARACTER_FOUR:
		default:
			break;
		}
	}

}
update_status GUI_Inventory::Update()
{
	Retexture();
	if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
	{
		if (App->gui->CheckButton(&Player1, App->input->mouse_x, App->input->mouse_y) && InventoryIs == OFF){
			InventoryIs = ON;
			InventoryCharacter = CHARACTER_ONE;
			Retexture();
		}
		if (App->gui->CheckButton(&Player2, App->input->mouse_x, App->input->mouse_y) && InventoryIs == ON){
			InventoryIs = OFF;
			InventoryCharacter = NO_CHARACTER;
			Retexture();
		}
	}
		return UPDATE_CONTINUE;
	
}

Character_Icon::Character_Icon(){

}
Inventory::Inventory(){

}
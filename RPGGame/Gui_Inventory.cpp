#include "SDL/include/SDL.h"
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
	InvectoryIs = OFF;
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
	if (InvectoryIs != OFF){
		App->render->Blit(Inventory, 490 * SCREEN_SIZE, 0 * SCREEN_SIZE, &Inventory_background);
	}

}
update_status GUI_Inventory::Update()
{
	Retexture();
	if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
	{
		if (CheckButton(&Player1, App->input->mouse_x, App->input->mouse_y) && InvectoryIs==OFF){
			InvectoryIs = ON;
			Retexture();
		}
		if (CheckButton(&Player2, App->input->mouse_x, App->input->mouse_y) && InvectoryIs == ON){
			InvectoryIs = OFF;
			Retexture();
		}
	}
		return UPDATE_CONTINUE;
	
}
bool GUI_Inventory::CheckButton(const SDL_Rect* button, int x, int y) const
{
	return (x< button->x*SCREEN_SIZE + button->w*SCREEN_SIZE  && x >= button->x*SCREEN_SIZE &&
		y < button->y*SCREEN_SIZE + button->h*SCREEN_SIZE  && y >= button->y*SCREEN_SIZE);
}
Character_Icon::Character_Icon(){

}
Inventory::Inventory(){

}
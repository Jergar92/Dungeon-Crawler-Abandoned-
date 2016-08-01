#include "Application.h"
#include "ModuleItems.h"
#include "Moduletexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

ModuleItems::ModuleItems()
{
	SDL_Rect key_sprite = { 0, 0, 52, 52 };
	map_items.push_back(Key = new Item("Key", "opens doors", 0, KEYS, key_sprite));
}

ModuleItems::~ModuleItems()
{
	delete Key;
	map_items.clear();
}

bool ModuleItems::Start()
{
	itemssprite = App->texture->Load("KEY.png");
	SDL_Rect hp_pot_sprite = { 0, 0, 52, 52 };
	App->player->formation[0]->inventory.push_back(HPPotion = new Item("HP Potion", "heals hp", 500, CONSUMABLE, hp_pot_sprite));
	return true;
}

update_status ModuleItems::Update()
{
	//App->render->Blit(itemssprite, 234, 232, &inventory.first_node->data->sprite);  for printing the inventory
	return UPDATE_CONTINUE;
}

bool ModuleItems::CleanUp()
{
	delete HPPotion;
	return true;
}
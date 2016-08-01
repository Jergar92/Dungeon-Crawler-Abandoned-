#include "Application.h"
#include "ModuleItems.h"
#include "Moduletexture.h"
#include"ModuleRender.h"


ModuleItems::ModuleItems()
{
	SDL_Rect keysprite = { 0, 0, 52, 52 };
	inventory.push_back(Key = new Item("Key", "opens doors", 0, KEYS, keysprite));// inventory.push_back(Key = new Item("Key", "opens doors", 0, KEYS, keysprite));
}

ModuleItems::~ModuleItems()
{
	delete Key;
	inventory.clear();
	
}

bool ModuleItems::Start()
{
	itemssprite = App->texture->Load("KEY.png");
	return true;
}

update_status ModuleItems::Update()
{
	//App->render->Blit(itemssprite, 234, 232, &inventory.first_node->data->sprite);  for printing the inventory
	return UPDATE_CONTINUE;
}

bool ModuleItems::CleanUp()
{
	return true;
}
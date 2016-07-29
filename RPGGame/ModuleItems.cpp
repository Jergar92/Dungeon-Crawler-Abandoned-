#include "Application.h"
#include "ModuleItems.h"

ModuleItems::ModuleItems()
{
	Item* Key; //MagneticCard(?)
	inventory.push_back(Key = new Item("Key", "opens doors", 0, KEYS));
}

ModuleItems::~ModuleItems()
{
	for (int i = 0; i < NUM_ITEMS; i++)
	{
		//TODO: Remove memory leaks from list
	}
	inventory.clear();
}

bool ModuleItems::Start()
{
	return true;
}

update_status ModuleItems::Update()
{
	return UPDATE_CONTINUE;
}

bool ModuleItems::CleanUp()
{
	return true;
}
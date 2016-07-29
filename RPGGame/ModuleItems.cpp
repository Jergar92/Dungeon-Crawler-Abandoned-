#include "Application.h"
#include "ModuleItems.h"

ModuleItems::ModuleItems()
{
	inventory.push_back(Key = new Item("Key", "opens doors", 0, KEYS));
}

ModuleItems::~ModuleItems()
{
	delete Key;
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
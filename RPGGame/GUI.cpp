#include "Application.h"
#include "GUI.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"

ModuleGui::ModuleGui()
{
	background = { 0, 0, 800, 600 };
}

ModuleGui::~ModuleGui()
{}

bool ModuleGui::Start()
{
	graphics = App->texture->Load("Gui_background.png");

	return true;
}

update_status ModuleGui::Update()
{
	App->render->Blit(graphics, 0, 0, &background);

	
	return UPDATE_CONTINUE;
}

bool ModuleGui::CleanUp()
{
	App->texture->Unload(graphics);
	return true;
}
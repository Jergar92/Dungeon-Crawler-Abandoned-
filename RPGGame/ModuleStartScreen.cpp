#include "Globals.h"
#include "SDL/include/SDL.h"
#include "Application.h"
#include "ModuleStartScreen.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"

ModuleStartScreen::ModuleStartScreen()
{
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

ModuleStartScreen::~ModuleStartScreen()
{}

bool ModuleStartScreen::Start()
{

	graphics = App->texture->Load("Game/NicoProJPG.png");

	return true;

}

update_status ModuleStartScreen::Update()
{
	App->render->Blit(graphics, 0, 0, &background);
	
	return UPDATE_CONTINUE;
}

bool ModuleStartScreen::CleanUp()
{
	App->texture->Unload(graphics);


	return true;
}
#include "Application.h"
#include "ModuleStartScreen.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleLevel1.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCollider.h"

ModuleStartScreen::ModuleStartScreen()
{
	background = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
}

ModuleStartScreen::~ModuleStartScreen()
{}

bool ModuleStartScreen::Start()
{
	graphics = App->texture->Load("Intro.png");
	return true;
}

update_status ModuleStartScreen::Update()
{
	App->render->Blit(graphics, 0, 0, &background);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_UP)
	{
		App->fade->FadeToBlack(this, (Module*)App->level1, 2.0f);
	}
	return UPDATE_CONTINUE;
}

bool ModuleStartScreen::CleanUp()
{
	App->texture->Unload(graphics);
	return true;
}
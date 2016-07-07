#include "Globals.h"
#include "Application.h"
#include "ModuleCommonLevels.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

ModuleCommonLevels::ModuleCommonLevels()
{
	Key_w = { 27, 1, 25, 26 };
	Key_a = { 2, 26, 26, 25 };
	Key_s = { 27, 26, 25, 25 };
	Key_d = { 51, 26, 26, 25 };
}
ModuleCommonLevels::~ModuleCommonLevels()
{}

bool ModuleCommonLevels::Start()
{
	App->collider->AddCollider(SDL_Rect{ 35, 200, 25, 26 }, COLLIDER_WALL);
	App->collider->AddCollider(SDL_Rect{ 10, 225, 26, 25 }, COLLIDER_WALL);
	App->collider->AddCollider(SDL_Rect{ 35, 225, 25, 25 }, COLLIDER_WALL);
	App->collider->AddCollider(SDL_Rect{ 60, 225, 26, 25 }, COLLIDER_WALL);

	Keys_wasd = App->texture->Load("WASD.png");

	bool ret = true;	
	LOG("Loading frontground assets");
	return ret;
}

bool ModuleCommonLevels::CleanUp()
{
	App->texture->Unload(Keys_wasd);
	LOG("Unloading Common Levels stuff");
	return true;
}

update_status ModuleCommonLevels::Update()
{
	App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_w);
	App->render->Blit(Keys_wasd, 10 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_a);
	App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_s);
	App->render->Blit(Keys_wasd, 60 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_d);
	return UPDATE_CONTINUE;
}

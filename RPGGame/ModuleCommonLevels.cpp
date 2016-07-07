#include "SDL/include/SDL.h"
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
	Coll_W = { 35, 200, 25, 26 };
	Coll_A = { 10, 225, 26, 25 };
	Coll_S = { 35, 225, 25, 25 };
	Coll_D = { 60, 225, 26, 25 };

	App->collider->AddCollider(Coll_W, COLLIDER_WALL);
	App->collider->AddCollider(Coll_A, COLLIDER_WALL);
	App->collider->AddCollider(Coll_S, COLLIDER_WALL);
	App->collider->AddCollider(Coll_D, COLLIDER_WALL);

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
	SDL_Event Event;
	bool running = true;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		}
	}
	if (Event.type == SDL_MOUSEBUTTONDOWN) // if the user clicked a mousebutton
	{
		if (App->collider->CheckButton(&App->commonlvls->Coll_W, Event.button.x, Event.button.y))
		{
			App->commonlvls->click_W = true;
		}
		else if (App->collider->CheckButton(&App->commonlvls->Coll_A, Event.button.x, Event.button.y))
		{
			App->commonlvls->click_A = true;
		}
		else if (App->collider->CheckButton(&App->commonlvls->Coll_S, Event.button.x, Event.button.y))
		{
			App->commonlvls->click_S = true;
		}
		else if (App->collider->CheckButton(&App->commonlvls->Coll_D, Event.button.x, Event.button.y))
		{
			App->commonlvls->click_D = true;
		}
	}

	return UPDATE_CONTINUE;
}

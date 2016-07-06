#include "Globals.h"
#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"


ModulePlayer::ModulePlayer()
{
	pasillo = { 0, 0, 384, 256 };
	direciones = { 0, 0, 384, 256 };
	fondo1 = { 0, 0, 384, 256 };
	fondo2 = { 0, 0, 384, 256 };
	fondo3 = { 0, 0, 384, 256 };
	position.x = 2;
	position.y = 3;
	test = { 100, 200, 1, 1 };
}

ModulePlayer::~ModulePlayer()
{
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	g_pasillo = App->texture->Load("Prube_sprite_recto.png");
	g_direciones = App->texture->Load("Prube_sprite_movimiento.png");
	g_fondo1 = App->texture->Load("Prube_sprite_fondo.png");
	g_fondo2 = App->texture->Load("Prube_sprite_fondo2.png");
	g_fondo3 = App->texture->Load("Prube_sprite_fondo3.png");
	return ret;
}
bool ModulePlayer::CleanUp()
{
	App->texture->Unload(g_pasillo);
	App->texture->Unload(g_direciones);
	App->texture->Unload(g_fondo1);
	App->texture->Unload(g_fondo2);
	App->texture->Unload(g_fondo3);
	return true;
}
// Update: draw background
update_status ModulePlayer::Update()
{

	if (1)
	{
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				position.y -= 1;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				position.x -= 1;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				position.y += 1;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				position.x += 1;
			}
		}
		num = App->level1->map[position.y][position.x];
		if (num == 1)
		{
			App->render->Blit(g_pasillo, 0, 0, &pasillo);
		}
		if (num == 2)
		{
			App->render->Blit(g_direciones, 0, 0, &direciones);
		}
		if (num == 3)
		{
			App->render->Blit(g_fondo1, 0, 0, &fondo1);
		}
		if (num == 4)
		{
			App->render->Blit(g_fondo2, 0, 0, &fondo2);
		}
		if (num == 5)
		{
			App->render->Blit(g_fondo3, 0, 0, &fondo3);
		}
		App->render->Blit(g_pasillo, position.x + 6, position.y + 6, &test);
	}


	return UPDATE_CONTINUE;
}
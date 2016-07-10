#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "ModuleCommonLevels.h"


ModulePlayer::ModulePlayer()
{
	corridor = { 0, 0, 384, 256 };
	corridorv1 = { 0, 0, 384, 256 };
	directions = { 0, 0, 384, 256 };
	directionsv1 = { 0, 0, 384, 256 };
	background1 = { 0, 0, 384, 256 };
	position.x = 1;
	position.y = 1;
	test = { 100, 200, 1, 1 };
	compass = { 3, 0, 30, 25 };
	exit = { 0, 0, 384, 256 };
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	direct = App->texture->Load("Direcion.png");
	g_corridor = App->texture->Load("Prube_sprite_recto.png");
	g_corridorv1 = App->texture->Load("Prube_sprite_rectov1.png");
	g_directions = App->texture->Load("Prube_sprite_movimiento.png");
	g_directionsv1 = App->texture->Load("Prube_sprite_movimientov1.png");
	g_background1 = App->texture->Load("Prube_sprite_fondo.png");
	g_exit = App->texture->Load("Prube_sprite_exit.png");
	direction = 3;
	return ret;
}
bool ModulePlayer::CleanUp()
{
	App->texture->Unload(g_corridor);
	App->texture->Unload(g_directions);
	App->texture->Unload(g_background1);
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (1)
	{
		//KEY W 
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || App->commonlvls->click_W == true)
		{
			if (App->level1->map[position.y][position.x] == 1)
			{
				changetile(1);
			}
			else if (App->level1->map[position.y][position.x] == 6)
			{
				changetile(1);
			}
			else if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(1);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(1);
			}
			App->commonlvls->click_W = false;
		}

		//KEY A
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP || App->commonlvls->click_A == true)
		{
			if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(2);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(2);
			}
			App->commonlvls->click_A = false;
		}

		//KEY S
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || App->commonlvls->click_S == true)
		{
			if (App->level1->map[position.y][position.x] == 1)
			{
				changetile(3);
			}
			else if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(3);
			}
			else if (App->level1->map[position.y][position.x] == 3)
			{
				changetile(3);
			}
			else if (App->level1->map[position.y][position.x] == 4)
			{
				changetile(3);
			}
			else if (App->level1->map[position.y][position.x] == 6)
			{
				changetile(3);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(3);
			}
			App->commonlvls->click_S = false;
		}

		//KEY D
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP || App->commonlvls->click_D == true)
		{
			if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(4);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(4);
			}
			App->commonlvls->click_D = false;
		}

		//Look new room
		num = App->level1->map[position.y][position.x];
		if (num == 1)
		{
			App->render->Blit(g_corridor, 0, 0, &corridor);
		}
		if (num == 2)
		{
			App->render->Blit(g_directions, 0, 0, &directions);
		}
		if (num == 3)
		{
			App->render->Blit(g_background1, 0, 0, &background1);
		}
		if (num == 4)
		{
			App->render->Blit(g_exit, 0, 0, &exit);
		}
		if (num == 6)
		{
			App->render->Blit(g_corridorv1, 0, 0, &corridorv1);
		}
		if (num == 7)
		{
			App->render->Blit(g_directionsv1, 0, 0, &directionsv1);
		}
		
		//Look in screen the new direction
		//Look NORTH
		if (direction == 1)
		{
			compass = { 8, 0, 18, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}
		//Look WEST
		if (direction == 2)
		{
			compass = { 28, 0, 30, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}
		//Look SOUTH
		if (direction == 3)
		{
			compass = { 60, 0, 16, 25 };
			App->render->Blit(direct, 10, 10, &compass);
		}
		//Look EAST
		if (direction == 4)
		{
			compass = { 78, 0, 15, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}

		//Look Test Point TILE
		App->render->Blit(g_corridor, position.x + 6, position.y + 6, &test);
	}
	return UPDATE_CONTINUE;
}

void ModulePlayer::changetile(int key)
{
	if (key == 1)
	{
		if (direction == 1)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				position.y -= 1;
			}
		}
		if (direction == 2)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				position.x -= 1;
			}
		}
		if (direction == 3)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				position.y += 1;
			}
		}
		if (direction == 4)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				position.x += 1;
			}
		}
	}

	if (key == 2)
	{
		if (direction == 1)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				direction = 2;
				position.x -= 1;
			}
		}
		if (direction == 2)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				direction = 3;
				position.y += 1;
			}
		}
		if (direction == 3)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				direction = 4;
				position.x += 1;
			}
		}
		if (direction == 4)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				direction = 1;
				position.y -= 1;
			}
		}
	}

	if (key == 3)
	{
		if (direction == 1)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				direction = 3;
				position.y += 1;
			}
		}
		else if (direction == 2)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				direction = 4;
				position.x += 1;
			}
		}
		else if (direction == 3)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				direction = 1;
				position.y -= 1;
			}
		}
		else if (direction == 4)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				direction = 2;
				position.x -= 1;
			}
		}
	}

	if (key == 4)
	{

		if (direction == 1)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				direction = 4;
				position.x += 1;
			}
		}
		if (direction == 2)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				direction = 1;
				position.y -= 1;
			}
		}
		if (direction == 3)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				direction = 2;
				position.x -= 1;
			}
		}
		if (direction == 4)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				direction = 3;
				position.y += 1;
			}
		}
	}
}
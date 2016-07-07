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
	pasillov1 = { 0, 0, 384, 256 };
	direciones = { 0, 0, 384, 256 };
	direcionesv1 = { 0, 0, 384, 256 };
	fondo1 = { 0, 0, 384, 256 };
	position.x = 1;
	position.y = 1;
	test = { 100, 200, 1, 1 };
	brujula = { 3, 0, 30, 25 };
	exit = { 0, 0, 384, 256 };
}

ModulePlayer::~ModulePlayer()
{
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	direct = App->texture->Load("Direcion.png");
	g_pasillo = App->texture->Load("Prube_sprite_recto.png");
	g_pasillov1 = App->texture->Load("Prube_sprite_rectov1.png");
	g_direciones = App->texture->Load("Prube_sprite_movimiento.png");
	g_direcionesv1 = App->texture->Load("Prube_sprite_movimientov1.png");
	g_fondo1 = App->texture->Load("Prube_sprite_fondo.png");
	g_exit = App->texture->Load("Prube_sprite_exit.png");
	direction = 3;
	return ret;
}
bool ModulePlayer::CleanUp()
{
	App->texture->Unload(g_pasillo);
	App->texture->Unload(g_direciones);
	App->texture->Unload(g_fondo1);
	return true;
}
// Update: draw background
update_status ModulePlayer::Update()
{

	if (1)
	{
		//KEY W 
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP)
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
		}

		//KEY A
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(2);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(2);
			}
		}
		//KEY S
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP)
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
		}
		//KEY D
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP)
		{
			if (App->level1->map[position.y][position.x] == 2)
			{
				changetile(4);
			}
			else if (App->level1->map[position.y][position.x] == 7)
			{
				changetile(4);
			}
		}

		//Look new room
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
			App->render->Blit(g_exit, 0, 0, &exit);
		}
		if (num == 6)
		{
			App->render->Blit(g_pasillov1, 0, 0, &pasillov1);
		}
		if (num == 7)
		{
			App->render->Blit(g_direcionesv1, 0, 0, &direcionesv1);
		}
		
		//Look in screen the new direction
		//Look NORTH
		if (direction == 1)
		{
			brujula = { 8, 0, 18, 25 };
			App->render->Blit(direct, 0, 0, &brujula);
		}
		//Look WEST
		if (direction == 2)
		{
			brujula = { 28, 0, 30, 25 };
			App->render->Blit(direct, 0, 0, &brujula);
		}
		//Look SOUTH
		if (direction == 3)
		{
			brujula = { 60, 0, 16, 25 };
			App->render->Blit(direct, 10, 10, &brujula);
		}
		//Look EAST
		if (direction == 4)
		{
			brujula = { 78, 0, 15, 25 };
			App->render->Blit(direct, 0, 0, &brujula);
		}

		//Look Test Point TILE
		App->render->Blit(g_pasillo, position.x + 6, position.y + 6, &test);
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
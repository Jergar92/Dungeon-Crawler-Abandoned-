#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

ModuleLevel1::ModuleLevel1()
{
	corridor = { 0, 0, 384, 256 };
	corridorv1 = { 0, 0, 384, 256 };
	directions = { 0, 0, 384, 256 };
	directionsv1 = { 0, 0, 384, 256 };
	background1 = { 0, 0, 384, 256 };
	exit = { 0, 0, 384, 256 };
	wall = { 0, 0, 384, 256 };

}
ModuleLevel1::~ModuleLevel1()
{}

bool ModuleLevel1::Start()
{
	bool ret = true;
	App->player->Enable();
	g_corridor = App->texture->Load("Pasillo_primero.png");
	g_corridorv1 = App->texture->Load("Pasillo_segundo.png");
	g_directions = App->texture->Load("Pasillo_tercero.png");
	g_directionsv1 = App->texture->Load("Prube_sprite_movimientov1.png");
	g_background1 = App->texture->Load("Prube_sprite_fondo.png");
	g_exit = App->texture->Load("Prube_sprite_exit.png");
	g_wall = App->texture->Load("Pared.png");
	int tile[10][10] = {

		//NOTICE: NEEDED THE FIRST && LAST LINE AND COLUMN TO BE 0 OR YOU CAN EXIT THE MAP
		/*      0  1  2  3  4  5  6  7  8  9
		/*0 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*1 */{ 4, 1, 6, 2, 7, 4, 0, 0, 0, 0 },
		/*2 */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		/*3 */{ 0, 0, 0, 4, 7, 4, 0, 0, 0, 0 },
		/*4 */{ 0, 0, 0, 0, 4, 0, 0, 0, 0, 0 },
		/*5 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*6 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*7 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*8 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*9 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	/*
	1-Pasillo recto
	2-Pasillo 4 esquinas
	3-fondo
	4-Exit
	6-Pasillo recto v2
	7-Pasillo 4 esquinas v2
	*/

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = tile[i][j];
		}
	}

	LOG("Loading background assets");
	return ret;
}

bool ModuleLevel1::CleanUp()
{
	LOG("Unloading Level1 stage");
	return true;
}

update_status ModuleLevel1::Update()
{

	App->player->room_tile[0] = App->level1->map[App->player->position.y][App->player->position.x];
	if (App->player->dir == NORTH)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y - 1][App->player->position.x];
		App->player->room_tile[2] = App->level1->map[App->player->position.y - 2][App->player->position.x];
	}
	else if (App->player->dir == EAST)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y][App->player->position.x + 1];
		App->player->room_tile[2] = App->level1->map[App->player->position.y][App->player->position.x + 2];
	}
	else if(App->player->dir == SOUTH)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y + 1][App->player->position.x];
		App->player->room_tile[2] = App->level1->map[App->player->position.y + 2][App->player->position.x];
	}
	else if(App->player->dir == WEST)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y][App->player->position.x - 1];
		App->player->room_tile[2] = App->level1->map[App->player->position.y][App->player->position.x - 2];

	}


	if (App->player->room_tile[1] == 0 && App->player->room_tile[0] != 4)
	{
		App->render->Blit(g_wall, 0, 0, &wall);
	}
	else
	{
		int i = 2;
		while (i >= 0)
		{
			switch (App->player->room_tile[i])
			{
			case 1:
				App->render->Blit(g_corridor, 0, 0, &corridor);
				break;
			case 2:
				App->render->Blit(g_directions, 0, 0, &directions);
				break;
			case 3:
				App->render->Blit(g_background1, 0, 0, &background1);
				break;
			case 4:
				App->render->Blit(g_exit, 0, 0, &exit);
				break;
			case 6:
				App->render->Blit(g_corridorv1, 0, 0, &corridorv1);
				break;
			case 7:
				App->render->Blit(g_directionsv1, 0, 0, &directionsv1);
				break;
			default:
				LOG("ERROR printing image tile");
				break;
			}
			i--;
		}
	}


	return UPDATE_CONTINUE;
}
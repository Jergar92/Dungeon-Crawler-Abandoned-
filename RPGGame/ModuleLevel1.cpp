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
	background_wall = { 0, 0, 600, 600 };
	lvl1_front_wall = { 0, 0, 600, 600 };
	lvl2_front_wall = { 600, 0, 600, 600 };
	lvl1_parallel_wall = { 1200, 0, 600, 600 };
	lvl2_large_front_wall = { 0, 600, 360, 360 };
	lvl2_parallel_wall = { 360, 600, 360, 360 };
	lvl3_front_wall = { 720, 600, 360, 360 };
	lvl3_large_front_wall = { 0, 960, 215, 215 };
	lvl3_parallel_wall = { 215, 960, 215, 215 };
	lvl4_front_wall = { 430, 960, 215, 215 };
	lvl4_large_front_wall = { 0, 1175, 135, 135 };
	lvl4_parallel_wall = { 135, 1175, 135, 135 };

}
ModuleLevel1::~ModuleLevel1()
{}

bool ModuleLevel1::Start()
{
	bool ret = true;
	App->player->Enable();
	graphics = App->texture->Load("spritesheet.png");

	int tile[10][10] = {

		//NOTICE: NEEDED THE FIRST && LAST LINE AND COLUMN TO BE 0 OR YOU CAN EXIT THE MAP
		/*      0  1  2  3  4  5  6  7  8  9
		/*0 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*1 */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		/*2 */{ 0, 1, 1, 1, 2, 1, 0, 0, 0, 0 },
		/*3 */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		/*4 */{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
		/*5 */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		/*6 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*7 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*8 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*9 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	/*
	1-Pasillo recto
	2-Pasillo 4 esquinas
	3-Exit
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
		App->player->room_tile[3] = App->level1->map[App->player->position.y - 3][App->player->position.x];
	}
	else if (App->player->dir == EAST)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y][App->player->position.x + 1];
		App->player->room_tile[2] = App->level1->map[App->player->position.y][App->player->position.x + 2];
		App->player->room_tile[3] = App->level1->map[App->player->position.y][App->player->position.x + 3];
	}
	else if(App->player->dir == SOUTH)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y + 1][App->player->position.x];
		App->player->room_tile[2] = App->level1->map[App->player->position.y + 2][App->player->position.x];
		App->player->room_tile[3] = App->level1->map[App->player->position.y + 3][App->player->position.x];
	}
	else if(App->player->dir == WEST)
	{
		App->player->room_tile[1] = App->level1->map[App->player->position.y][App->player->position.x - 1];
		App->player->room_tile[2] = App->level1->map[App->player->position.y][App->player->position.x - 2];
		App->player->room_tile[3] = App->level1->map[App->player->position.y][App->player->position.x - 3];
	}

	if (App->player->room_tile[1] == 0 && App->player->room_tile[0] != 4)
	{
		App->render->Blit(graphics, 0, 0, &background_wall);
	}
	else
	{
		App->render->Blit(graphics, 0, 0, &background_wall);

		if (App->player->room_tile[3] != 0)
		{
			App->render->Blit(graphics, 234, 232, &lvl4_parallel_wall);
		}
		else
		{
			App->render->Blit(graphics, 234, 232, &lvl4_large_front_wall);
		}
		//level 3 render
		switch (App->player->room_tile[2])
		{
		case 1:
			App->render->Blit(graphics, 191, 192, &lvl3_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 191, 192, &lvl4_front_wall);
			break;
		case 0:
			App->render->Blit(graphics, 191, 192, &lvl3_large_front_wall);
			break;
		default:
			LOG("ERROR printing image tile");
			break;
		}
		//Level 2 render
		switch (App->player->room_tile[1])
		{
		case 1:
			App->render->Blit(graphics, 121, 120, &lvl2_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 121, 120, &lvl3_front_wall);
			break;
		case 0:
			App->render->Blit(graphics, 121, 120, &lvl2_large_front_wall);
			break;
		default:
			LOG("ERROR printing image tile");
			break;
		}

		//Level 1 render
		switch (App->player->room_tile[0])
		{
		case 1:
			App->render->Blit(graphics, 0, 0, &lvl1_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 0, 0, &lvl2_front_wall);
			break;
		case 0:
			App->render->Blit(graphics, 0, 0, &lvl1_front_wall);
			break;
		default:
			LOG("ERROR printing image tile");
			break;
		}
	}


	return UPDATE_CONTINUE;
}
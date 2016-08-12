#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"
#include "ModuleEnemies.h"
#include "Blue_Enemy.h"

ModuleLevel1::ModuleLevel1()
{
	//Backgound sprites
	background_wall = { 1200, 0, 600, 600 };
	
	//Front walls sprites
	lvl1_front_wall = { 0, 0, 600, 600 };
	lvl2_front_wall = { 600, 0, 600, 600 };
	lvl3_front_wall = { 285, 600, 285, 284 };
	lvl4_front_wall = { 2000000, 20000, 215, 215 };

	//Paralel walls sprites
	lvl1_parallel_wall = { 0, 0, 600, 600 };
	lvl2_parallel_wall = { 0, 600, 285, 285 };
	lvl3_parallel_wall = { 0, 885, 187, 184 };
	//lvl4_parallel_wall = { 135, 1175, 135, 135 };

	//Large front walls sprites
	lvl2_large_front_wall = { 570, 600, 285, 285 };
	lvl3_large_front_wall = { 373, 885, 188, 184 };
	lvl4_large_front_wall = { 0, 1070, 138, 138 };
	
	//Doors sprites
	lvl1_closed_door = { 285, 0, 285, 285 };
	lvl2_closed_door = { 285, 0, 285, 275 };
	lvl3_closed_door = { 285, 277, 184, 184 };
	lvl4_closed_door = {2073, 912, 135, 135 };
	
	lvl1_right_opened_door = { 0, 0, 285, 285 };
	lvl2_right_opened_door = { 0, 0, 285, 275 };
	lvl3_right_opened_door = { 0, 278, 188, 184 };
	lvl4_right_opened_door = { 135, 1175, 135, 135 };
	
	lvl1_left_opened_door = { 1211, 659, 600, 600 };
	lvl2_left_opened_door = { 1356,1327, 360, 360 };
	lvl3_left_opened_door = { 1466, 1796, 215, 215 };
	lvl4_left_opened_door = { 1517, 2070, 135, 135 };
}
ModuleLevel1::~ModuleLevel1()
{}

bool ModuleLevel1::Start()
{
	bool ret = true;

	App->player->Enable();
	App->enemies->Enable();

	graphics = App->texture->Load("levelspritesheet.png");
	test_graphics = App->texture->Load("doorsspritesheet.png");

	int tile[10][10] = {

		//NOTICE: NEEDED THE FIRST && LAST LINE AND COLUMN TO BE 0 OR YOU CAN EXIT THE MAP
		/*      0  1  2  3  4  5  6  7  8  9
		/*0 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*1 */{ 0, 9, 9, 9, 1, 9, 0, 0, 0, 0 },
		/*2 */{ 0, 1, 1, 3, 2, 1, 0, 0, 0, 0 },
		/*3 */{ 0, 9, 9, 9, 1, 9, 0, 0, 0, 0 },
		/*4 */{ 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
		/*5 */{ 0, 0, 0, 9, 1, 9, 0, 0, 0, 0 },
		/*6 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*7 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*8 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*9 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	/*
	1-Pasillo recto
	2-Pasillo 4 esquinas
	3-Puerta
	4-Puerta abierta
	5-Salida
	*/

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j] = tile[i][j];
		}
	}

	// Enemies ---
	App->enemies->AddEnemy(ENEMY_TYPES::BLUE, 4, 4, 100, 10, 10,1000,9000);
	App->enemies->AddEnemy(ENEMY_TYPES::RED, 4, 3, 100, 10, 10,1000,9000);
	App->enemies->AddEnemy(ENEMY_TYPES::GREEN, 4, 1, 100, 10, 10, 1000, 9000);
	

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

	if (App->player->room_tile[1] == 0){
		App->render->Blit(graphics, 0, 0, &background_wall);
		App->render->Blit(graphics, 0, 0, &lvl1_parallel_wall);
		App->render->Blit(graphics, 158, 158, &lvl2_large_front_wall);
	}
	else if (App->player->room_tile[1] == 9){
		App->render->Blit(graphics, 0, 0, &background_wall);
		App->render->Blit(graphics, 0, 0, &lvl2_front_wall);
		App->render->Blit(graphics, 158, 158, &lvl2_large_front_wall);
	}
	else{
		App->render->Blit(graphics, 0, 0, &background_wall);

		//level 4 render
		switch (App->player->room_tile[3])
		{
		case 1:
			App->render->Blit(graphics, 234, 232, &lvl4_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 234, 232, &lvl4_parallel_wall);
			break;
		case 3:
			App->render->Blit(test_graphics, 234, 234, &lvl4_closed_door);
			break;
		case 4:
			if (App->player->dir == NORTH || App->player->dir == EAST)App->render->Blit(test_graphics, 234, 234, &lvl4_right_opened_door);
			else App->render->Blit(test_graphics, 234, 234, &lvl4_left_opened_door);
			break;
		case 0:
			App->render->Blit(graphics, 234, 232, &lvl4_large_front_wall);
			break;
		default:
			LOG("ERROR printing image tile");
			break;
		}
		//level 3 render
		switch (App->player->room_tile[2])
		{
		case 1:
			App->render->Blit(graphics, 209, 208, &lvl3_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 191, 192, &lvl4_front_wall);
			break;
		case 3:
			App->render->Blit(graphics, 209, 209, &lvl3_parallel_wall);
			App->render->Blit(test_graphics, 209, 206, &lvl3_right_opened_door);
			App->render->Blit(test_graphics, 210, 205, &lvl3_closed_door);
			break;
		case 4:
			App->render->Blit(graphics, 209, 209, &lvl3_parallel_wall);
			App->render->Blit(test_graphics, 209, 206, &lvl3_right_opened_door);
			break;
		case 0:
			App->render->Blit(graphics, 208, 209, &lvl3_large_front_wall);
			break;
		default:
			LOG("ERROR printing image tile");
			break;
		}
		//Level 2 render
		switch (App->player->room_tile[1])
		{
		case 1:
			App->render->Blit(graphics, 157, 158, &lvl2_parallel_wall);
			break;
		case 2:
			App->render->Blit(graphics, 157, 157, &lvl3_front_wall);
			break;
		case 3:
			App->render->Blit(graphics, 157, 158, &lvl2_parallel_wall);
			App->render->Blit(test_graphics, 160, 163, &lvl2_right_opened_door);
			App->render->Blit(test_graphics, 162, 165, &lvl2_closed_door);
			break;
		case 4:
			App->render->Blit(graphics, 157, 158, &lvl2_parallel_wall);
			App->render->Blit(test_graphics, 160, 163, &lvl2_right_opened_door);
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
		case 3:
			App->render->Blit(test_graphics, 157, 157, &lvl1_closed_door);
			break;
		case 4:
			App->render->Blit(graphics, 0, 0, &lvl1_parallel_wall);
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

void ModuleLevel1::open_close_door(){
	if (App->player->room_tile[1] == 3){
		switch (App->player->dir){
		case NORTH:
			App->level1->map[App->player->position.y - 1][App->player->position.x] = 4;
			break;
		case SOUTH:
			App->level1->map[App->player->position.y + 1][App->player->position.x] = 4;
			break;
		case EAST:
			App->level1->map[App->player->position.y][App->player->position.x + 1] = 4;
			break;
		case WEST:
			App->level1->map[App->player->position.y][App->player->position.x - 1] = 4;
			break;
		}
	}
	else if (App->player->room_tile[1] == 4){
		switch (App->player->dir){
		case NORTH:
			App->level1->map[App->player->position.y - 1][App->player->position.x] = 3;
			break;
		case SOUTH:
			App->level1->map[App->player->position.y + 1][App->player->position.x] = 3;
			break;
		case EAST:
			App->level1->map[App->player->position.y][App->player->position.x + 1] = 3;
			break;
		case WEST:
			App->level1->map[App->player->position.y][App->player->position.x - 1] = 3;
			break;
		}
	}
}
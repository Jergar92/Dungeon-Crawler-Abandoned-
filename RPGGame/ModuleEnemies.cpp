#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTexture.h"
#include "Enemy.h"
#include "Blue_Enemy.h"
#include "ModuleLevel1.h"
#include "ModulePlayer.h"


#define SPAWN_MARGIN 50

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;

	//Blue Enemy
	lvl1_blue = { 16, 22, 135, 194 };
	lvl2_blue = { 16, 225, 77, 105 };
	lvl3_blue = { 16, 338, 39, 55 };
	lvl4_blue = { 16, 401, 24, 34 };
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->texture->Load("Enemies.png");
	int enemy_tile[10][10] = {

		//NOTICE: NEEDED THE FIRST && LAST LINE AND COLUMN TO BE 9 OR YOU CAN EXIT THE MAP
		/*      0  1  2  3  4  5  6  7  8  9
		/*0 */{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		/*1 */{ 9, 9, 9, 9, 0, 9, 9, 9, 9, 9 },
		/*2 */{ 9, 0, 0, 0, 1, 0, 9, 9, 9, 9 },
		/*3 */{ 9, 9, 9, 9, 0, 9, 9, 9, 9, 9 },
		/*4 */{ 9, 9, 9, 0, 0, 0, 9, 9, 9, 9 },
		/*5 */{ 9, 9, 9, 9, 0, 9, 9, 9, 9, 9 },
		/*6 */{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		/*7 */{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		/*8 */{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
		/*9 */{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
	};
	/*
	1-Blue Enemy
	*/

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			enemy_map[i][j] = enemy_tile[i][j];
		}
	}
	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	/*for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Draw(sprites);*/
	if (enemy_map[App->player->position.y][App->player->position.x] == 1)
	{
		App->render->Blit(sprites, 234, 232, &lvl1_blue);
	}

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (/*Enemic mort*/ 0)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->texture->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::BLUE_ENEMY:
			enemies[i] = new Blue_Enemy(info.x, info.y);
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			App->particles->AddParticle(App->particles->explosion, enemies[i]->position.x, enemies[i]->position.y);
			delete enemies[i];
			enemies[i] = nullptr;
			break;
		}
	}
}
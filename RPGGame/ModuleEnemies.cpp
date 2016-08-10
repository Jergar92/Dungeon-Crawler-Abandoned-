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
#include "Blue_Enemy.h"

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		enemies[i] = nullptr;
	}
}

ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	sprites = App->texture->Load("Enemies.png");
	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			SpawnEnemy(queue[i]);
			queue[i].type = ENEMY_TYPES::NO_TYPE;
			LOG("Spawning enemy at [%i][%i]\n", App->enemies->queue[i].y, App->enemies->queue[i].x);
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr)
		{
			enemies[i]->Move();
		}
	}
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (App->player->dir == NORTH)
		{	
			if (CheckMonster(App->player->position.x, App->player->position.y - 1, i))
			{
				if (CanSeePlayer(App->player->position.x, App->player->position.y - 1, i))
					enemies[i]->Draw_close(sprites);
			}
			if (CheckMonster(App->player->position.x, App->player->position.y - 2, i))
			{
				if (CanSeePlayer(App->player->position.x, App->player->position.y - 2, i))
					enemies[i]->Draw_medium(sprites);
			}
		}
		else if (App->player->dir == EAST)
		{
			if (CheckMonster(App->player->position.x+1, App->player->position.y, i))
			{
				if (CanSeePlayer(App->player->position.x + 1, App->player->position.y, i))
				enemies[i]->Draw_close(sprites);
			}
			if (CheckMonster(App->player->position.x+2, App->player->position.y, i))
			{
				if (CanSeePlayer(App->player->position.x + 2, App->player->position.y, i))
				enemies[i]->Draw_medium(sprites);
			}
		}
		else if (App->player->dir == SOUTH)
		{
			if (CheckMonster(App->player->position.x, App->player->position.y + 1, i))
			{
				if (CanSeePlayer(App->player->position.x, App->player->position.y + 1, i))
				enemies[i]->Draw_close(sprites);
			}
			if (CheckMonster(App->player->position.x, App->player->position.y + 2, i))
			{
				if (CanSeePlayer(App->player->position.x, App->player->position.y + 2, i))
				enemies[i]->Draw_medium(sprites);
			}
		}
		else if (App->player->dir == WEST)
		{
			if (CheckMonster(App->player->position.x - 1, App->player->position.y, i))
			{
				if (CanSeePlayer(App->player->position.x - 1, App->player->position.y, i))
				enemies[i]->Draw_close(sprites);
			}
			if (CheckMonster(App->player->position.x - 2, App->player->position.y, i))
			{
				if (CanSeePlayer(App->player->position.x - 2, App->player->position.y, i))
				enemies[i]->Draw_medium(sprites);
			}
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr)
		{
			if (queue[i].hp <= 0)
			{
				LOG("Enemy died at[%i][%i]\n", App->level1->map[queue[i].y][queue[i].x]);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}
	return UPDATE_CONTINUE;
}

bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");
	App->texture->Unload(sprites);

	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}
	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y, int hp, int attack, int defense)
{
	bool ret = false;
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			queue[i].hp = hp;
			queue[i].attack = attack;
			queue[i].defense = defense;
			ret = true;
			break;
		}
	}
	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; i++);
	
	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::BLUE:
		{
			enemies[i] = new Blue_Enemy(info.x, info.y, info.hp, info.attack, info.defense);
			break;
		}
		}
	}
}

//void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)

bool ModuleEnemies::CheckMonster(int x, int y, int i)
{
	bool ret = false;

	if (queue[i].x == x && queue[i].y == y)
	{
		ret = true;
	}
	return ret;
}

bool ModuleEnemies::CanSeePlayer(int x, int y, int i)
{
	int checkY = y, checkX = x;
	bool ret = true;
	if (queue[i].x == checkX && queue[i].y == checkY)
		{
			while ((App->player->position.y != checkY) || (App->player->position.x != checkX)){

				if (App->level1->map[checkY][checkX] == 0 || App->level1->map[checkY][checkX] == 3){
				ret = false;
				return ret;
			}
			if (App->player->position.x < checkX)
				checkX--;
			else if (App->player->position.x > checkX)
				checkX++;
			if (App->player->position.y < checkY)
				checkY--;
			else if (App->player->position.y > checkY)
				checkY++;
		}
	}
	return ret;
}
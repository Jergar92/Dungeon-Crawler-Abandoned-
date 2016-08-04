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
			LOG("Spawning enemy at [%i][%i]\n", App->level1->map[queue[i].y][queue[i].x]);
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
			//enemies[i]->Move();
		}
	}
	for (uint i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies[i] != nullptr)
		{
			//enemies[i]->Draw(sprites);
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
	/*
	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::BLUE:
		{
			enemies[i] = new Enemy_Blue(info.x, info.y, info.hp, info.attack, info.defense);
			break;
		}
		case ENEMY_TYPES::RED:
		{
			enemies[i] = new Enemy_Red(info.x, info.y, info.hp, info.attack, info.defense);
			break;
		}
		case ENEMY_TYPES::GREEN:
		{
			enemies[i] = new Enemy_Green(info.x, info.y, info.hp, info.attack, info.defense);
			break;
		}
		}
	}*/
}

//void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)

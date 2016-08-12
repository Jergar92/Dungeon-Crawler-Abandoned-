#include "Application.h"
#include "ModulePlayer.h"
#include "Green_Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "stdlib.h"
#include "ModuleLevel1.h"
#include <time.h>

Green_Enemy::Green_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay) :Enemy(x, y, hp, attack, defense, at_delay, mov_delay)
{
	position.x = x;
	position.y = y;

	close.PushBack({ 1183, 27, 109, 109 });
	medium.PushBack({ 646, 149, 57, 57 });

	//To modify
	distant.PushBack({ 16, 225, 77, 105 });

	animation_close = &close;
	animation_medium = &medium;
	animation_distant = &distant;
}

void Green_Enemy::Move()
{
	if (actual_time >= timer + mov_delay)
	{
		timer = actual_time;
		srand(time(NULL));

		int dir = rand() % 4;
		switch (dir)
		{
			//NORTH
		case 0:
		{
			if (EnemyCanPass(position.y - 1, position.x))
			{
				position.y -= 1;
				LOG("Moved to NORTH");
			}
			break;
		}
		//EAST
		case 1:
		{
			if (EnemyCanPass(position.y, position.x + 1))
			{
				position.x += 1;
				LOG("Moved to EAST");
			}
			break;
		}
		//SOUTH
		case 2:
		{
			if (EnemyCanPass(position.y + 1, position.x))
			{
				position.y += 1;
				LOG("Moved to SOUTH");
			}
			break;
		}
		//WEST
		case 3:
		{
			if (EnemyCanPass(position.y, position.x - 1))
			{
				position.x -= 1;
				LOG("Moved to WEST");
			}
			break;
		}
		default:
		{
			LOG("NO MOVEMENT");
			break;
		}
		}
	}
}
bool Green_Enemy::EnemyCanPass(int posY, int posX){
	bool ret = false;
	if (App->level1->map[posY][posX] != 0 && App->level1->map[posY][posX] != 3 && App->level1->map[posY][posX] != 9)
		{
			if (App->player->position.x == position.x &&App->player->position.y == position.y)
				ret = false;
			else
				ret = true;
		}
		return ret;
	}

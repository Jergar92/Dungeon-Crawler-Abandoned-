#include "Application.h"
#include "Blue_Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "stdlib.h"
#include <time.h>

Blue_Enemy::Blue_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay) :Enemy(x, y, hp, attack, defense, at_delay, mov_delay)
{
	original_pos.x = x;
	original_pos.y = y;

	close.PushBack({ 28, 31, 111, 103 });
	medium.PushBack({ 25, 152, 59, 54 });

	//To modify
	distant.PushBack({ 16, 225, 77, 105 });

	animation_close = &close;
	animation_medium = &medium;
	animation_distant = &distant;
}

void Blue_Enemy::Move()
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
			if (original_pos.y - 1 != 0)
			{
				original_pos.y -= 1;
				LOG("Moved to NORTH");
			}
			break;
		}
		//EAST
		case 1:
		{
			if (original_pos.x + 1 != 0)
			{
				original_pos.x += 1;
				LOG("Moved to EAST");
			}
			break;
		}
		//SOUTH
		case 2:
		{
			if (original_pos.y + 1 != 0)
			{
				original_pos.y += 1;
				LOG("Moved to SOUTH");
			}
			break;
		}
		//WEST
		case 3:
		{
			if (original_pos.x - 1 != 0)
			{
				original_pos.x -= 1;
				LOG("Moved to WEST");
			}
				break;
		}
		}

	}

}


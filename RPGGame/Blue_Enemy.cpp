#include "Application.h"
#include "ModulePlayer.h"
#include "Blue_Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "stdlib.h"
#include "ModuleLevel1.h"
#include <time.h>

Blue_Enemy::Blue_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay, direction direction) :Enemy(x, y, hp, attack, defense, at_delay, mov_delay,direction)
{
	position.x = x;
	position.y = y;

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
		switch (dir)
		{
		//NORTH
		case NORTH:
		{
			if (EnemyCanPass(position.y - 1,position.x))
			{
				position.y -= 1;
				LOG("Moved to NORTH");
			}
			break;
		}
		//EAST
		case EAST:
		{
			if (EnemyCanPass(position.y,position.x + 1))
			{
				position.x += 1;
				LOG("Moved to EAST");
			}
			break;
		}
		//SOUTH
	 case SOUTH:
		{
			if (EnemyCanPass(position.y + 1,position.x))
			{
				position.y += 1;
				LOG("Moved to SOUTH");
			}
			break;
		}
		//WEST
		case WEST:
		{
			if (EnemyCanPass(position.y,position.x - 1))
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
bool Blue_Enemy::EnemyCanPass(int posY, int posX){
	bool ret = false;
	if (App->level1->map[posY][posX] != 0 && App->level1->map[posY][posX] != 3 && App->level1->map[posY][posX] != 9)
	{
		if (App->player->position.x == posX &&App->player->position.y == posY)
			ret = false;
		else
			ret = true;
	}
	return ret;
}
void Blue_Enemy::Rotation()
{
	rotation rot = static_cast<rotation>(rand() % 2);

	if (rot == RIGHT)
	{
		switch (dir)
		{
		case NORTH:
			dir = EAST;
			break;
		case SOUTH:
			dir = WEST;
			break;
		case EAST:
			dir = SOUTH;
			break;
		case WEST:
			dir = NORTH;
			break;
		default:
			LOG("ERROR rotating player");
			break;
		}
	}
	else if (rot == LEFT)
	{
		switch (dir)
		{
		case NORTH:
			dir = WEST;
			break;
		case SOUTH:
			dir = EAST;
			break;
		case EAST:
			dir = NORTH;
			break;
		case WEST:
			dir = SOUTH;
			break;
		default:
			LOG("ERROR rotating player");
			break;
		}
	}
}
bool Blue_Enemy::EnemyCanGoTo(){
	bool ret = false;
	switch (dir)
	{
	case NORTH:
	
		if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3 && App->level1->map[position.y - 1][position.x] != 9)
		{
			ret = true;
		}
		break;
	case SOUTH:
		if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3 && App->level1->map[position.y + 1][position.x] != 9)
		{
			ret = true;
		}
		break;
	
	case EAST:
		
		if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3 && App->level1->map[position.y][position.x + 1] != 9)
		{
			ret = true;
		}
		break;
	case WEST:
		if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3 && App->level1->map[position.y][position.x - 1] != 9)
		{
			ret = true;
		}
		break;
	default:
		break;
	}
	return ret;
}

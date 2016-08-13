#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "Green_Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "stdlib.h"
#include "ModuleLevel1.h"
#include <time.h>

Green_Enemy::Green_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay, direction direction) :Enemy(x, y, hp, attack, defense, at_delay, mov_delay, direction)
{
	position.x = x;
	position.y = y;
	formation = ONLEFT;
	close_Front = { 1183, 26, 109, 109 };//35
	close_Back = { 1327, 26, 109, 109 };//144
	close_Left = { 1471, 26, 109, 109 };
	close_Right = { 1615, 26, 109, 109 };

	medium_Front = { 646, 149, 57, 57 };//76
	medium_Back = { 722, 149, 57, 57 };
	medium_Left = { 798, 149, 57, 57 };
	medium_Right = { 874, 149, 57, 57 };

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
		switch (dir)
		{
			//NORTH
		case NORTH:
		{
			if (EnemyCanPass(position.y - 1, position.x))
			{
				position.y -= 1;
				LOG("Moved to NORTH");
			}
			break;
		}
		//EAST
		case EAST:
		{
			if (EnemyCanPass(position.y, position.x + 1))
			{
				position.x += 1;
				LOG("Moved to EAST");
			}
			break;
		}
		//SOUTH
		case SOUTH:
		{
			if (EnemyCanPass(position.y + 1, position.x))
			{
				position.y += 1;
				LOG("Moved to SOUTH");
			}
			break;
		}
		//WEST
		case WEST:
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
		if (App->player->position.x == posX &&App->player->position.y == posY)
			ret = false;
		else
			ret = true;
	}
	return ret;
}
void Green_Enemy::Rotation()
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
bool Green_Enemy::EnemyCanGoTo(){
	bool ret = false;
	int counter = 0;
	switch (dir)
	{
	case NORTH:

		if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3 && App->level1->map[position.y - 1][position.x] != 9)
		{
			for (int i = 0; i < MAX_ENEMIES; i++){
				if (App->enemies->enemies[i] != nullptr){
					if (App->enemies->enemies[i]->position.x == position.x &&App->enemies->enemies[i]->position.y == position.y - 1){
						counter++;
					}
				}
				if (counter == 2){
					return ret;
				}

			}
			ret = true;
		}
		break;
	case SOUTH:
		if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3 && App->level1->map[position.y + 1][position.x] != 9)
		{
			for (int i = 0; i < MAX_ENEMIES; i++){
				if (App->enemies->enemies[i] != nullptr){
					if (App->enemies->enemies[i]->position.x == position.x &&App->enemies->enemies[i]->position.y == position.y + 1){
						counter++;
					}
				}
				if (counter == 2){
					return ret;
				}

			}
			ret = true;
		}
		break;

	case EAST:

		if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3 && App->level1->map[position.y][position.x + 1] != 9)
		{
			for (int i = 0; i < MAX_ENEMIES; i++){
				if (App->enemies->enemies[i] != nullptr){
					if (App->enemies->enemies[i]->position.x + 1 == position.x &&App->enemies->enemies[i]->position.y == position.y){
						counter++;
					}
				}
				if (counter == 2){
					return ret;
				}

			}
			ret = true;
		}
		break;
	case WEST:
		if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3 && App->level1->map[position.y][position.x - 1] != 9)
		{
			for (int i = 0; i < MAX_ENEMIES; i++){
				if (App->enemies->enemies[i] != nullptr){
					if (App->enemies->enemies[i]->position.x == position.x - 1 && App->enemies->enemies[i]->position.y == position.y){
						counter++;
					}
				}
				if (counter == 2){
					return ret;
				}

			}
			ret = true;
		}
		break;
	default:
		break;
	}
	return ret;
}

#include "Application.h"
#include "Blue_Enemy.h"
#include "ModuleCollider.h"

Blue_Enemy::Blue_Enemy(int x, int y) :Enemy(x, y)
{
	original_pos.x = x;
	original_pos.y = y;
}

void Blue_Enemy::Move()
{

}
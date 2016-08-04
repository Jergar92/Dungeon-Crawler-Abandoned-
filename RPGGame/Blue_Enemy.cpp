#include "Application.h"
#include "Blue_Enemy.h"
#include "ModuleCollider.h"

Blue_Enemy::Blue_Enemy(int x, int y,int hp,int attack, int defense) :Enemy(x, y,hp,attack,defense)
{
	original_pos.x = x;
	original_pos.y = y;
}

void Blue_Enemy::Move()
{

}
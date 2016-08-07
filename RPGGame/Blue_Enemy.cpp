#include "Application.h"
#include "Blue_Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"

Blue_Enemy::Blue_Enemy(int x, int y, int hp, int attack, int defense) :Enemy(x, y, hp, attack, defense)
{
	original_pos.x = x;
	original_pos.y = y;

	close.PushBack({ 16, 22, 135, 194 });
	medium.PushBack({ 16, 225, 77, 105 });
	distant.PushBack({ 16, 225, 77, 105 });

	animation_close = &close;
	animation_medium = &medium;
	animation_distant = &distant;
}

void Blue_Enemy::Move()
{
}


#include "Application.h"
#include "Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

Enemy::Enemy(int x, int y, int hp, int attack, int defense) :position(x, y),
hp(hp), attack(attack), defense(defense), collider(nullptr){}

Enemy::~Enemy()
{
	if (collider != nullptr)
	{
		App->collider->EraseCollider(collider);
	}
}

//const Collider* Enemy::GetCollider() const

void Enemy::Draw_close(SDL_Texture* sprites)
{
	App->render->Blit(sprites, 234, 232, &(animation->GetCurrentFrame()));
}

void Enemy::Draw_medium(SDL_Texture* sprites)
{
	App->render->Blit(sprites, 234, 232, &(animation->GetCurrentFrame()));
}

void Enemy::Draw_far(SDL_Texture* sprites)
{
	App->render->Blit(sprites, 234, 232, &(animation->GetCurrentFrame()));
}

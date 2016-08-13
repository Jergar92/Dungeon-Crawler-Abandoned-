#include "Application.h"
#include "Enemy.h"
#include "ModuleCollider.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

Enemy::Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay, direction direction) :position(x, y),
hp(hp), attack(attack), defense(defense), at_delay(at_delay), mov_delay(mov_delay), collider(nullptr), dir(direction){}

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
	if (formation==ONLEFT)
	App->render->Blit(sprites, 180, 370, &(animation_close->GetCurrentFrame()));
	else
	App->render->Blit(sprites, 350, 370, &(animation_close->GetCurrentFrame()));

}

void Enemy::Draw_medium(SDL_Texture* sprites)
{
	if (formation==ONLEFT)
		App->render->Blit(sprites, 230, 360, &(animation_medium->GetCurrentFrame()));
	else
		App->render->Blit(sprites, 350, 370, &(animation_close->GetCurrentFrame()));
}

void Enemy::Draw_distant(SDL_Texture* sprites)
{
	if (formation == ONLEFT)
		App->render->Blit(sprites, 300, 300, &(animation_distant->GetCurrentFrame()));
	else
		App->render->Blit(sprites, 350, 300, &(animation_close->GetCurrentFrame()));
}

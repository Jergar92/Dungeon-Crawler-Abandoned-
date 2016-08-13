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
	switch (dir)
	{
	case NORTH:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Back);
			else
				App->render->Blit(sprites, 350, 370, &close_Back);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Front);
			else
				App->render->Blit(sprites, 350, 370, &close_Front);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Right);
			else
				App->render->Blit(sprites, 350, 370, &close_Right);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Left);
			else
				App->render->Blit(sprites, 350, 370, &close_Left);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case SOUTH:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Front);
			else
				App->render->Blit(sprites, 350, 370, &close_Front);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Back);
			else
				App->render->Blit(sprites, 350, 370, &close_Back);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Left);
			else
				App->render->Blit(sprites, 350, 370, &close_Left);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Right);
			else
				App->render->Blit(sprites, 350, 370, &close_Right);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case EAST:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Right);
			else
				App->render->Blit(sprites, 350, 370, &close_Right);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Left);
			else
				App->render->Blit(sprites, 350, 370, &close_Left);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Back);
			else
				App->render->Blit(sprites, 350, 370, &close_Back);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Front);
			else
				App->render->Blit(sprites, 350, 370, &close_Front);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case WEST:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Left);
			else
				App->render->Blit(sprites, 350, 370, &close_Left);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Right);
			else
				App->render->Blit(sprites, 350, 370, &close_Right);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Front);
			else
				App->render->Blit(sprites, 350, 370, &close_Front);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &close_Back);
			else
				App->render->Blit(sprites, 350, 370, &close_Back);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	default:
		LOG("ERROR");
		break;
	}
	

}

void Enemy::Draw_medium(SDL_Texture* sprites)
{
	switch (dir)
	{
	case NORTH:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Back);
			else
				App->render->Blit(sprites, 350, 370, &medium_Back);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Front);
			else
				App->render->Blit(sprites, 350, 370, &medium_Front);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Right);
			else
				App->render->Blit(sprites, 350, 370, &medium_Right);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Left);
			else
				App->render->Blit(sprites, 350, 370, &medium_Left);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case SOUTH:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Front);
			else
				App->render->Blit(sprites, 350, 370, &medium_Front);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Back);
			else
				App->render->Blit(sprites, 350, 370, &medium_Back);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Left);
			else
				App->render->Blit(sprites, 350, 370, &medium_Left);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Right);
			else
				App->render->Blit(sprites, 350, 370, &medium_Right);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case EAST:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Right);
			else
				App->render->Blit(sprites, 350, 370, &medium_Right);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Left);
			else
				App->render->Blit(sprites, 350, 370, &medium_Left);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Back);
			else
				App->render->Blit(sprites, 350, 370, &medium_Back);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Front);
			else
				App->render->Blit(sprites, 350, 370, &medium_Front);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	case WEST:
		switch (App->player->dir)
		{
		case NORTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Left);
			else
				App->render->Blit(sprites, 350, 370, &medium_Left);
			break;
		case SOUTH:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Right);
			else
				App->render->Blit(sprites, 350, 370, &medium_Right);
			break;
		case EAST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Front);
			else
				App->render->Blit(sprites, 350, 370, &medium_Front);
			break;
		case WEST:
			if (formation == ONLEFT)
				App->render->Blit(sprites, 180, 370, &medium_Back);
			else
				App->render->Blit(sprites, 350, 370, &medium_Back);
			break;
		default:
			LOG("ERROR");
			break;
		}
		break;
	default:
		LOG("ERROR");
		break;
	}
}

void Enemy::Draw_distant(SDL_Texture* sprites)
{
	if (formation == ONLEFT)
		App->render->Blit(sprites, 300, 300, &(animation_distant->GetCurrentFrame()));
	else
		App->render->Blit(sprites, 350, 300, &(animation_close->GetCurrentFrame()));
}

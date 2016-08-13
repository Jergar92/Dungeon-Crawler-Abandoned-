#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "windows.h"

struct SDL_Texture;
struct Collider;
//enum EnemyState{PATROL,FOLLOWING,ATTACKING};
class Enemy
{
protected:
	Animation* animation_close;
	Animation* animation_medium;
	Animation* animation_distant;
	Collider* collider;

public:
	iPoint position;
	int hp;
	int attack;
	int defense;
	int at_delay;
	int mov_delay;
	direction dir;
	rotation rot;
	//time counter
	uint timer = GetTickCount();
	uint actual_time;

	Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay, direction direction);
	virtual ~Enemy();

	//const Collider* GetCollider() const;

	virtual void Move(){};
	virtual void Rotation(){};
	virtual bool EnemyCanPass(int posY, int posX) = 0;
	virtual bool EnemyCanGoTo() = 0;
	virtual void Draw_close(SDL_Texture* sprites);
	virtual void Draw_medium(SDL_Texture* sprites);
	virtual void Draw_distant(SDL_Texture* sprites);
};

#endif // __ENEMY_H__
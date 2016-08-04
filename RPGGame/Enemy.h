#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class Enemy
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;
	int hp;
	int attack;
	int defense;

	Enemy(int x, int y, int hp, int attack, int defense);
	virtual ~Enemy();

	//const Collider* GetCollider() const;

	virtual void Move(){};
	virtual void Draw_close(SDL_Texture* sprites);
	virtual void Draw_medium(SDL_Texture* sprites);
	virtual void Draw_far(SDL_Texture* sprites);
};

#endif // __ENEMY_H__
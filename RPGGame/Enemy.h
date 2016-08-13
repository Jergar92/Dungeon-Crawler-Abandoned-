#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"
#include "ModulePlayer.h"
#include "windows.h"

struct SDL_Texture;
struct Collider;
//enum EnemyState{PATROL,FOLLOWING,ATTACKING}
enum EnemyFormation{ONLEFT,ONRIGHT};
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
	EnemyFormation formation;
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

	SDL_Rect close_Front;
	SDL_Rect close_Right;
	SDL_Rect close_Left;
	SDL_Rect close_Back;

	SDL_Rect medium_Front;
	SDL_Rect medium_Right;
	SDL_Rect medium_Left;
	SDL_Rect medium_Back;
	/* ///No implemented///
	SDL_Rect distant_Front;
	SDL_Rect distant_Right;
	SDL_Rect distant_Left;
	SDL_Rect distant_Back;
	*/
};

#endif // __ENEMY_H__
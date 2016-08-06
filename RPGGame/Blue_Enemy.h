#ifndef __BLUE_ENEMY_H__
#define __BLUE_ENEMY_H__

#include "Enemy.h"


class Blue_Enemy : public Enemy
{
private:
	iPoint original_pos;
	Animation close;
	Animation medium;
	Animation distant;

public:

	Blue_Enemy(int x, int y,int hp, int attack,int defense);
	void Move();
	
};


#endif // __BLUE_ENEMY_H__

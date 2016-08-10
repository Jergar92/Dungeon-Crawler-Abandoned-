#ifndef __BLUE_ENEMY_H__
#define __BLUE_ENEMY_H__

#include "Enemy.h"


class Blue_Enemy : public Enemy
{
private:
	Animation close;
	Animation medium;
	Animation distant;

public:

	Blue_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay);
	void Move();
	
};


#endif // __BLUE_ENEMY_H__

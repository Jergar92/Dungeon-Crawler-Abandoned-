#ifndef __RED_ENEMY_H__
#define __RED_ENEMY_H__

#include "Enemy.h"


class Red_Enemy : public Enemy
{
private:
	
	Animation close;
	Animation medium;
	Animation distant;

public:

	Red_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay);
	void Move();

};


#endif // __RED_ENEMY_H__
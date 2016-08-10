#ifndef __GREEN_ENEMY_H__
#define __GREEN_ENEMY_H__

#include "Enemy.h"


class Green_Enemy : public Enemy
{
private:
	Animation close;
	Animation medium;
	Animation distant;

public:

	Green_Enemy(int x, int y, int hp, int attack, int defense, int at_delay, int mov_delay);
	void Move();

};


#endif // __GREEN_ENEMY_H__

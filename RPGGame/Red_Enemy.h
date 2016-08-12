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
	bool EnemyCanPass(int posY, int posX);

};


#endif // __RED_ENEMY_H__
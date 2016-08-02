#ifndef __BLUE_ENEMY_H__
#define __BLUE_ENEMY_H__

#include "Enemy.h"

class Blue_Enemy : public Enemy
{
private:
	iPoint original_pos;

public:

	Blue_Enemy(int x, int y);
	SDL_Texture* front = nullptr;
	void Move();
};


#endif // __BLUE_ENEMY_H__

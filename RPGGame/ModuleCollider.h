#ifndef __ModuleCollider_H__
#define __ModuleCollider_H__

#define MAX_COLLIDERS 200
#define NUM_COLLIDERS 3

#include "Module.h"

enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL,
	COLLIDER_PLAYER,
};


struct Collider
{
	SDL_Rect rect;

	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;

	Collider(COLLIDER_TYPE type, Module* callback = nullptr) :
		type(type),
		callback(callback)
	{}
	
	virtual bool CheckCollision(const Collider* c) const = 0;
	virtual void SetPos(int x, int y) = 0;
};


struct ColliderRect : public Collider
{
	ColliderRect(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) : Collider(type, callback)
	{
		rect = rectangle;
	}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const Collider* c) const;
};


class ModuleCollider : public Module
{
public:

	ModuleCollider();
	~ModuleCollider();

	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();

private:

	Collider* colliders[MAX_COLLIDERS];
	bool matrix[NUM_COLLIDERS][NUM_COLLIDERS];
	bool debug = false;
};

#endif // __ModuleCollider_H__
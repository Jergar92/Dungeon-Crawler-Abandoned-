#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Vector.h"
#include "String.h"

struct SDL_Texture;
#define NUM_PLAYERS 4

enum direction{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum rotation{
	RIGHT,
	LEFT
};

class Player{
public:
	Player(String name, int hp, int mp, int attack, int defense) :name(name), hp(hp), mp(mp), attack(attack), defense(defense) {}
	~Player(){}
	String name;
	int hp, mp, attack, defense;
	bool PlayerDead = false;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	void CreatePlayers();
	void DeletePlayers();
	Vector<Player*> formation;

	SDL_Texture* g_corridor = nullptr;
	SDL_Texture* g_corridorv1 = nullptr;
	SDL_Texture* g_directions = nullptr;
	SDL_Texture* g_directionsv1 = nullptr;
	SDL_Texture* g_background1 = nullptr;
	SDL_Texture* direct = nullptr;
	SDL_Texture* g_exit = nullptr;

	iPoint position;
	SDL_Rect corridor;
	SDL_Rect corridorv1;
	SDL_Rect directions;
	SDL_Rect directionsv1;
	SDL_Rect background1;
	SDL_Rect test;
	SDL_Rect exit;
	SDL_Rect compass;

	direction dir;
	int room_tile[3];
	bool cant_cross = false;

	void PlayerInput();
	void PlayerRotation(int, rotation);
	void ChangeTile(int);
	void CompassPrint(int);
};

#endif
#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Globals.h"
#include "p2Point.h"
#include "Vector.h"
#include "String.h"
#include "DoubleList.h"

struct SDL_Texture;
#define NUM_PLAYERS 4

enum player_class{
	WARRIOR,
	ROGUE,
	ARCHER,
	MAGE
};

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
	Player(String name, int max_hp, int hp, int mp, int attack, int defense) :name(name), max_hp(max_hp), hp(hp), mp(mp), attack(attack), defense(defense) {}
	~Player(){}
	String name;
	int max_hp, hp, mp, attack, defense;
	bool PlayerDead = false;
};

enum item_type{
	WEAPON,
	SHIELD,
	ARMOUR,
	CONSUMABLE,		//Potions or more dmg/def temporary (?)
	KEYS
};

class Items{
	Items(String name, String description, int value, item_type type) : name(name), description(description), value(value), type(type){}
	~Items(){}
	String name;
	String description;
	int value;
	item_type type;
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
	Vector<Player*> formation;
	DoubleList<Items*> inventory;


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
	int room_tile[4];
	bool cant_cross = false;

	void PlayerInput();
	void PlayerRotation(int, rotation);
	void ChangeTile(int);
	void CompassPrint(int);
};

#endif




/*	

	background_wall = { 0, 0, 600, 600 };
	lvl1_front_wall = { 0, 0, 600, 600 };
	lvl2_front_wall = { 600, 0, 600, 600 };
	lvl1_parallel_wall = { 1200, 0, 600, 600 };
	lvl2_large_front_wall = { 0, 600, 360, 360 };
	lvl2_parallel_wall = { 360, 600, 360, 360 };
	lvl3_front_wall = { 720, 600, 360, 360 };
	lvl3_large_front_wall = { 0, 960, 215, 215 };
	lvl3_parallel_wall = { 215, 960, 215, 215 };
	lvl4_front_wall = { 430, 960, 215, 215 };
	lvl4_large_front_wall = { 0, 1175, 135, 135 };
	lvl4_parallel_wall = { 135, 1175, 135, 135 };
	
	*/
#ifndef __ModuleItems_H__
#define __ModuleItems_H__

#include "Module.h"
#include "Globals.h"
#include "String.h"
#include "DoubleList.h"
struct SDL_Texture;
enum item_type{
	WEAPON,
	SHIELD,
	ARMOUR,
	CONSUMABLE,		//Potions or more dmg/def temporary (?)
	KEYS
};



class Item{
public:
	Item(String name, String description, int value, item_type type, SDL_Rect sprite) : name(name), description(description), value(value), type(type), sprite(sprite){}
	~Item(){}
	String name;
	String description;
	int value;
	item_type type;
	SDL_Rect sprite;

};

class ModuleItems : public Module{
public:
	ModuleItems();
	~ModuleItems();
	SDL_Texture* itemssprite = nullptr;
	bool Start();
	update_status Update();
	bool CleanUp();

public:
	DoubleList<Item*> inventory;
	Item* Key; //MagneticCard(?)
	
};

#endif //__ModuleItems_H__
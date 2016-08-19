#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 18

class Module;
class ModuleWindow;
class ModuleInput;
class ModuleRender;
class ModuleAudio;
class ModuleTextures;
class ModuleStartScreen;
class ModuleLevel1;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleCollider;
class ModuleGui;
class GUI_Character;
class GUI_Movement;
class GUI_Inventory;
class ModuleEnemies;
class ModuleParticles;
class ModuleItems;
class ModuleMinigames;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleInput* input;
	ModuleRender* render;
	ModuleAudio* audio;
	ModuleTextures* texture;
	ModuleStartScreen* menu_screen;
	ModulePlayer* player;
	ModuleLevel1* level1;
	ModuleFadeToBlack* fade;
	ModuleCollider* collider;
	GUI_Character* gui_character;
	GUI_Movement* gui_movement;
	GUI_Inventory* gui_inventory;
	ModuleGui* gui;
	ModuleEnemies* enemies;
	ModuleParticles* particles;
	ModuleMinigames* minigames;
	ModuleItems* items;


public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__
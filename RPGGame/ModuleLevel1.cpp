#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"

ModuleLevel1::ModuleLevel1()
{

}
ModuleLevel1::~ModuleLevel1()
{}

bool ModuleLevel1::Start()
{
	bool ret = true;
	int tile[5][5] = {
		/*      0  1  2  
		/*0 */{ 0, 0, 0, 0, 0 },
		/*1 */{ 0, 0, 3, 0, 0 },
		/*2 */{ 0, 4, 2, 5, 0 },
			  { 0, 0, 1, 0, 0 },
		      { 0, 0, 0, 0, 0 },
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			map[i][j] = tile[i][j];
		}
	}

	LOG("Loading background assets");
	return ret;
}

bool ModuleLevel1::CleanUp()
{
	LOG("Unloading Level1 stage");
	return true;
}

update_status ModuleLevel1::Update()
{

	return UPDATE_CONTINUE;
}

















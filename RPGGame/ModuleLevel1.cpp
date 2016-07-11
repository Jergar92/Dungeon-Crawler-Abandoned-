#include "Globals.h"
#include "Application.h"
#include "ModuleLevel1.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

ModuleLevel1::ModuleLevel1()
{}
ModuleLevel1::~ModuleLevel1()
{}

bool ModuleLevel1::Start()
{
	bool ret = true;
	App->player->Enable();

	int tile[10][10] = {

		//NOTICE: NEEDED THE FIRST && LAST LINE AND COLUMN TO BE 0 OR YOU CAN EXIT THE MAP
		/*      0  1  2  3  4  5  6  7  8  9
		/*0 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*1 */{ 0, 1, 6, 1, 7, 4, 0, 0, 0, 0 },
		/*2 */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
		/*3 */{ 0, 0, 0, 4, 7, 4, 0, 0, 0, 0 },
		/*4 */{ 0, 0, 0, 0, 4, 0, 0, 0, 0, 0 },
		/*5 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*6 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*7 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*8 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		/*9 */{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};
	/*
	1-Pasillo recto
	2-Pasillo 4 esquinas
	3-fondo
	4-Exit
	6-Pasillo recto v2
	7-Pasillo 4 esquinas v2
	*/

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
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
#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "ModuleUI.h"
#include <stdlib.h>
#include <time.h>

ModulePlayer::ModulePlayer()
{
	corridor = { 0, 0, 384, 256 };
	corridorv1 = { 0, 0, 384, 256 };
	directions = { 0, 0, 384, 256 };
	directionsv1 = { 0, 0, 384, 256 };
	background1 = { 0, 0, 384, 256 };
	test = { 100, 200, 1, 1 };
	compass = { 3, 0, 30, 25 };
	exit = { 0, 0, 384, 256 };

	//Player position
	position.x = 1;
	position.y = 1;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	direct = App->texture->Load("Direcion.png");
	g_corridor = App->texture->Load("Prube_sprite_recto.png");
	g_corridorv1 = App->texture->Load("Prube_sprite_rectov1.png");
	g_directions = App->texture->Load("Prube_sprite_movimiento.png");
	g_directionsv1 = App->texture->Load("Prube_sprite_movimientov1.png");
	g_background1 = App->texture->Load("Prube_sprite_fondo.png");
	g_exit = App->texture->Load("Prube_sprite_exit.png");
	dir = EAST;

	CreatePlayers();
	return ret;
}

bool ModulePlayer::CleanUp()
{
	App->texture->Unload(g_corridor);
	App->texture->Unload(g_directions);
	App->texture->Unload(g_background1);
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (1)
	{
		PlayerInput();

		room_tile[0] = App->level1->map[position.y][position.x];

		CompassPrint(dir);
	}
	return UPDATE_CONTINUE;
}

void ModulePlayer::CreatePlayers()
{
	Player* Warrior;
	Player* Rogue;
	Player* Archer;
	Player* Mage;
	formation.PushBack(Warrior = new Player("Warrior", 2000, 250, 150, 200));
	formation.PushBack(Rogue = new Player("Rogue", 1250, 500, 200, 100));
	formation.PushBack(Archer = new Player("Archer", 1100, 500, 250, 50));
	formation.PushBack(Mage = new Player("Mage", 1100, 1000, 250, 50));
}

void ModulePlayer::DeletePlayers()
{
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		delete formation[i];
	}
}

void ModulePlayer::PlayerInput()
{
	//ATTACK TEST
	//F1 - ENEMY NORTH FROM PLAYER
	//F2 - ENEMY SOUTH FROM PLAYER
	//F3 - ENEMY EAST FROM PLAYER
	//F4 - ENEMY WEST FROM PLAYER

	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[1]->hp -= 1000; }
			break;
		case SOUTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[2]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case EAST:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[2]->hp -= 1000; }
			break;
		case WEST:
			i = rand() % 2;
			if		(i == 0)	{ formation[1]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		default:
			LOG("ERROR player direction.");
			break;
		}
		for (int j = 0; j < NUM_PLAYERS; j++)
		{
			if (formation[j]->hp <= 0)
			{
				formation[j]->PlayerDead = true;
			}
		}
		CheckDeads();
	}

	else if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[2]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case SOUTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[1]->hp -= 1000; }
			break;
		case EAST:
			i = rand() % 2;
			if		(i == 0)	{ formation[1]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case WEST:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[2]->hp -= 1000; }
			break;
		default:
			LOG("ERROR player direction.");
			break;
		}
		for (int j = 0; j < NUM_PLAYERS; j++)
		{
			if (formation[j]->hp <= 0)
			{
				formation[j]->PlayerDead = true;
			}
		}
		CheckDeads();
	}

	else if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[1]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case SOUTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[2]->hp -= 1000; }
			break;
		case EAST:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 0)	{ formation[1]->hp -= 1000; }
			break;
		case WEST:
			i = rand() % 2;
			if		(i == 0)	{ formation[2]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		default:
			LOG("ERROR player direction.");
			break;
		}
		for (int j = 0; j < NUM_PLAYERS; j++)
		{
			if (formation[j]->hp <= 0)
			{
				formation[j]->PlayerDead = true;
			}
		}
		CheckDeads();
	}

	else if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[2]->hp -= 1000; }
			break;
		case SOUTH:
			i = rand() % 2;
			if		(i == 0)	{ formation[1]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case EAST:
			i = rand() % 2;
			if		(i == 0)	{ formation[2]->hp -= 1000; }
			else if (i == 1)	{ formation[3]->hp -= 1000; }
			break;
		case WEST:
			i = rand() % 2;
			if		(i == 0)	{ formation[0]->hp -= 1000; }
			else if (i == 1)	{ formation[1]->hp -= 1000; }
			break;
		default:
			LOG("ERROR player direction.");
			break;
		}
		for (int j = 0; j < NUM_PLAYERS; j++)
		{
			if (formation[j]->hp <= 0)
			{
				formation[j]->PlayerDead = true;
			}
		}
		CheckDeads();
	}
	//--


	//FRONT
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || App->ui->click_W == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		App->ui->click_W = false;
	}
	
	//BACK
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || App->ui->click_S == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				dir = SOUTH; 
				ChangeTile(dir);
				dir = NORTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				dir = NORTH;
				ChangeTile(dir);
				dir = SOUTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				dir = WEST;
				ChangeTile(dir);
				dir = EAST;
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				dir = EAST;
				ChangeTile(dir);
				dir = WEST;
			}
			else{ cant_cross = true; }
		}		
		App->ui->click_S = false;
	}

	//RIGHT
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP || App->ui->click_D == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				dir = EAST; 
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				dir = WEST;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				dir = SOUTH;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				dir = NORTH;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		App->ui->click_D = false;
	}

	//LEFT
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP || App->ui->click_A == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				dir = WEST; 
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				dir = EAST;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				dir = NORTH;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				dir = SOUTH;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		App->ui->click_A = false;
	}

	if (cant_cross == true)
	{
		//TODO Message "you can't go that way"
		cant_cross = false;
	}

	//ROTATION
		//RIGHT
	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_UP || App->ui->click_E == true) //TODO: MOUSE CLICK
	{
		PlayerRotation(dir, RIGHT);
		App->ui->click_E = false;
	}

		//LEFT
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_UP || App->ui->click_Q == true) //TODO: MOUSE CLICK
	{
		PlayerRotation(dir, LEFT);
		App->ui->click_Q= false;
	}
}

void ModulePlayer::ChangeTile(int direction)
{
	switch (direction)
	{
	case NORTH:
		position.y -= 1;
		break;
	case SOUTH:
		position.y += 1;
		break;
	case WEST:
		position.x -= 1;
		break;
	case EAST:
		position.x += 1;
		break;
	default:
		LOG("ERROR moving player");
		break;
	}
}

void ModulePlayer::PlayerRotation(int direction, rotation rot)
{
	if (rot == RIGHT)
	{
		switch (direction)
		{
		case NORTH:
			dir = EAST;
			break;
		case SOUTH:
			dir = WEST;
			break;
		case EAST:
			dir = SOUTH;
			break;
		case WEST:
			dir = NORTH;
			break;
		default:
			LOG("ERROR rotating player");
			break;
		}
	}
	else if (rot == LEFT)
	{
		switch (direction)
		{
		case NORTH:
			dir = WEST;
			break;
		case SOUTH:
			dir = EAST;
			break;
		case EAST:
			dir = NORTH;
			break;
		case WEST:
			dir = SOUTH;
			break;
		default:
			LOG("ERROR rotating player");
			break;
		}
	}
}


void ModulePlayer::CompassPrint(int direction)
{
	switch (direction)
	{
	case NORTH:
		compass = { 8, 0, 18, 25 };
		App->render->Blit(direct, 0, 0, &compass);
		break;

	case SOUTH:
		compass = { 60, 0, 16, 25 };
		App->render->Blit(direct, 10, 10, &compass);
		break;

	case EAST:
		compass = { 78, 0, 15, 25 };
		App->render->Blit(direct, 0, 0, &compass);
		break;

	case WEST:
		compass = { 28, 0, 30, 25 };
		App->render->Blit(direct, 0, 0, &compass);
		break;

	default: LOG("ERROR printing compass");
		break;
	}
}

void ModulePlayer::CheckDeads()
{
	if (formation[0]->PlayerDead == true)	{ LOG("WARRIOR DEAD"); }
	if (formation[1]->PlayerDead == true)	{ LOG("ROGUE DEAD"); }
	if (formation[2]->PlayerDead == true)	{ LOG("ARCHER DEAD"); }
	if (formation[3]->PlayerDead == true)	{ LOG("MAGE DEAD"); }
}
#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "GUI_Movement.h"
#include "ModuleWindow.h"
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
	position.y = 2;

	Player* Warrior;
	Player* Rogue;
	Player* Archer;
	Player* Mage;
	formation.PushBack(Warrior = new Player("Warrior", 2000, 2000, 250, 250, 150, 200));
	formation.PushBack(Rogue = new Player("Rogue", 1250, 1250, 500, 500, 200, 100));
	formation.PushBack(Archer = new Player("Archer", 1100, 1100, 500, 500, 250, 50));
	formation.PushBack(Mage = new Player("Mage", 1100, 1100, 1000, 1000, 250, 50));
}

ModulePlayer::~ModulePlayer()
{
	if (App->player->formation[0]->PlayerDead == true)	{ LOG("WARRIOR DEAD"); }
	if (App->player->formation[1]->PlayerDead == true)	{ LOG("ROGUE DEAD"); }
	if (App->player->formation[2]->PlayerDead == true)	{ LOG("ARCHER DEAD"); }
	if (App->player->formation[3]->PlayerDead == true)	{ LOG("MAGE DEAD"); }
	
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		delete formation[i];
	}
}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	direct = App->texture->Load("directions.png");
	g_corridor = App->texture->Load("Prube_sprite_recto.png");
	g_corridorv1 = App->texture->Load("Prube_sprite_rectov1.png");
	g_directions = App->texture->Load("Prube_sprite_movimiento.png");
	g_directionsv1 = App->texture->Load("Prube_sprite_movimientov1.png");
	g_background1 = App->texture->Load("Prube_sprite_fondo.png");
	g_exit = App->texture->Load("Prube_sprite_exit.png");
	dir = EAST;

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

void ModulePlayer::PlayerInput()
{
	//ATTACK TEST
	//F1 - ENEMY NORTH FROM PLAYER
	//F2 - ENEMY SOUTH FROM PLAYER
	//F3 - ENEMY EAST FROM PLAYER
	//F4 - ENEMY WEST FROM PLAYER
	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_UP)App->level1->open_close_door();
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true){ i = 1; }
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[ROGUE]->PlayerDead == true){ formation[MAGE]->hp -= 1000; }
						else { formation[ROGUE]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			break;

		case SOUTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true)
					{
						if (formation[ARCHER]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ARCHER]->hp -= 1000; }
					}
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case EAST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true){ i = 1; }
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ROGUE]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			break;

		case WEST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true)
					{
						if (formation[ROGUE]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ROGUE]->hp -= 1000; }
					}
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
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
	}

	else if (App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true)
					{
						if (formation[ARCHER]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ARCHER]->hp -= 1000; }
					}
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case SOUTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true){ i = 1; }
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ARCHER]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			break;

		case EAST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true)
					{
						if (formation[ROGUE]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ROGUE]->hp -= 1000; }
					}
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case WEST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true){ i = 1; }
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ROGUE]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
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
	}

	else if (App->input->keyboard[SDL_SCANCODE_F3] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true)
					{
						if (formation[ROGUE]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ROGUE]->hp -= 1000; }
					}
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case SOUTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true){ i = 1; }
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ROGUE]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			break;

		case EAST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true){ i = 1; }
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ARCHER]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			break;

		case WEST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true)
					{
						if (formation[ARCHER]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ARCHER]->hp -= 1000; }
					}
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
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
	}

	else if (App->input->keyboard[SDL_SCANCODE_F4] == KEY_STATE::KEY_UP)
	{
		srand(time(NULL));
		int i = 0;
		switch (dir)
		{
		case NORTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true){ i = 1; }
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ROGUE]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			break;

		case SOUTH:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true)
					{
						if (formation[ROGUE]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ROGUE]->hp -= 1000; }
					}
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case EAST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[ARCHER]->PlayerDead == true)
				{
					if (formation[WARRIOR]->PlayerDead == true){ i = 1; }
					else{ formation[WARRIOR]->hp -= 1000; }
				}
				else{ formation[ARCHER]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[MAGE]->PlayerDead == true)
				{
					if (formation[ROGUE]->PlayerDead == true)
					{
						if (formation[ARCHER]->PlayerDead == true){ formation[WARRIOR]->hp -= 1000; }
						else { formation[ARCHER]->hp -= 1000; }
					}
					else{ formation[ROGUE]->hp -= 1000; }
				}
				else{ formation[MAGE]->hp -= 1000; }
			}
			break;

		case WEST:
			i = rand() % 2;
			if (i == 0)
			{
				if (formation[WARRIOR]->PlayerDead == true)
				{
					if (formation[ARCHER]->PlayerDead == true){ i = 1; }
					else{ formation[ARCHER]->hp -= 1000; }
				}
				else{ formation[WARRIOR]->hp -= 1000; }
			}
			else if (i == 1)
			{
				if (formation[ROGUE]->PlayerDead == true)
				{
					if (formation[MAGE]->PlayerDead == true)
					{
						if (formation[WARRIOR]->PlayerDead == true){ formation[ARCHER]->hp -= 1000; }
						else { formation[WARRIOR]->hp -= 1000; }
					}
					else{ formation[MAGE]->hp -= 1000; }
				}
				else{ formation[ROGUE]->hp -= 1000; }
			}
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
	}
	//--


	//FRONT
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || App->gui_movement->click_W == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3)
			{
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		App->gui_movement->click_W = false;
	}

	//BACK
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || App->gui_movement->click_S == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3)
			{
				dir = SOUTH;
				ChangeTile(dir);
				dir = NORTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3)
			{
				dir = NORTH;
				ChangeTile(dir);
				dir = SOUTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3)
			{
				dir = WEST;
				ChangeTile(dir);
				dir = EAST;
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3)
			{
				dir = EAST;
				ChangeTile(dir);
				dir = WEST;
			}
			else{ cant_cross = true; }
		}
		App->gui_movement->click_S = false;
	}

	//RIGHT
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP || App->gui_movement->click_D == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3)
			{
				dir = EAST;
				ChangeTile(dir);
				dir = NORTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3)
			{
				dir = WEST;
				ChangeTile(dir);
				dir = SOUTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3)
			{
				dir = SOUTH;
				ChangeTile(dir);
				dir = EAST;
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3)
			{
				dir = NORTH;
				ChangeTile(dir);
				dir = WEST;
			}
			else{ cant_cross = true; }
		}
		App->gui_movement->click_D = false;
	}

	//LEFT
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP || App->gui_movement->click_A == true)
	{
		if (dir == NORTH)
		{
			if (App->level1->map[position.y][position.x - 1] != 0 && App->level1->map[position.y][position.x - 1] != 3)
			{
				dir = WEST;
				ChangeTile(dir);
				dir = NORTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y][position.x + 1] != 0 && App->level1->map[position.y][position.x + 1] != 3)
			{
				dir = EAST;
				ChangeTile(dir);
				dir = SOUTH;
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y - 1][position.x] != 0 && App->level1->map[position.y - 1][position.x] != 3)
			{
				dir = NORTH;
				ChangeTile(dir);
				dir = EAST;
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y + 1][position.x] != 0 && App->level1->map[position.y + 1][position.x] != 3)
			{
				dir = SOUTH;
				ChangeTile(dir);
				dir = WEST;
			}
			else{ cant_cross = true; }
		}
		App->gui_movement->click_A = false;
	}

	if (cant_cross == true)
	{
		//TODO Message "you can't go that way"
		cant_cross = false;
	}

	//ROTATION
	//RIGHT
	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_STATE::KEY_UP || App->gui_movement->click_E == true)
	{
		PlayerRotation(dir, RIGHT);
		App->gui_movement->click_E = false;
	}

	//LEFT
	if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_UP || App->gui_movement->click_Q == true)
	{
		PlayerRotation(dir, LEFT);
		App->gui_movement->click_Q = false;
	}

	if (App->input->keyboard[SDL_SCANCODE_LALT] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_RETURN] == KEY_STATE::KEY_REPEAT)
	{
		if (App->window->full_screen == false)		{ App->window->full_screen = true; }
		else if (App->window->full_screen == true)	{ App->window->full_screen = false; }

		App->window->ChangeWindowSize();
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
		compass = { 0, 0, 200, 40 };
		App->render->Blit(direct, 200, 0, &compass);
		break;

	case SOUTH:
		compass = { 0, 80, 200, 40 };
		App->render->Blit(direct, 200, 0, &compass);
		break;

	case EAST:
		compass = { 0, 40, 200, 40 };
		App->render->Blit(direct, 200, 0, &compass);
		break;

	case WEST:
		compass = { 0, 120, 200, 40 };
		App->render->Blit(direct, 200, 0, &compass);
		break;

	default: LOG("ERROR printing compass");
		break;
	}
}
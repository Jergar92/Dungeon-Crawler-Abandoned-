#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "ModuleCommonLevels.h"
#include "ModuleUI.h"

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

		room_tile = App->level1->map[position.y][position.x];
		PlayerMovementImage(room_tile);

		CompassPrint(dir);
	}
	return UPDATE_CONTINUE;
}

void ModulePlayer::PlayerInput()
{
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
			}
			else{ cant_cross = true; }
		}
		else if (dir == SOUTH)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				dir = NORTH;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == EAST)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				dir = WEST;
				ChangeTile(dir);
			}
			else{ cant_cross = true; }
		}
		else if (dir == WEST)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				dir = EAST;
				ChangeTile(dir);
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

void ModulePlayer::PlayerMovementImage(int room_tile)
{
	switch (room_tile)
	{
	case 1:
		App->render->Blit(g_corridor, 0, 0, &corridor);
		break;
	case 2:
		App->render->Blit(g_directions, 0, 0, &directions);
		break;
	case 3:
		App->render->Blit(g_background1, 0, 0, &background1);
		break;
	case 4:
		App->render->Blit(g_exit, 0, 0, &exit);
		break;
	case 6:
		App->render->Blit(g_corridorv1, 0, 0, &corridorv1);
		break;
	case 7:
		App->render->Blit(g_directionsv1, 0, 0, &directionsv1);
		break;
	default:
		LOG("ERROR printing image tile");
		break;
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

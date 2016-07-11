#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleLevel1.h"
#include "ModuleCommonLevels.h"


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
		//NORTH
		if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || App->commonlvls->click_W == true)
		{
			if (App->level1->map[position.y - 1][position.x] != 0)
			{
				dir = NORTH;
				ChangeTile(dir);
			}
			else
			{
				//TODO Message "you can't go that way"
			}
			App->commonlvls->click_W = false;
		}

		//SOUTH
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || App->commonlvls->click_S == true)
		{
			if (App->level1->map[position.y + 1][position.x] != 0)
			{
				dir = SOUTH;
				ChangeTile(dir);
			}
			else
			{
				//TODO Message "you can't go that way"
			}
			App->commonlvls->click_S = false;
		}

		//EAST
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP || App->commonlvls->click_D == true)
		{
			if (App->level1->map[position.y][position.x + 1] != 0)
			{
				dir = EAST;
				ChangeTile(dir);
			}
			else
			{
				//TODO Message "you can't go that way"
			}
			App->commonlvls->click_D = false;
		}

		//WEST
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP || App->commonlvls->click_A == true)
		{
			if (App->level1->map[position.y][position.x - 1] != 0)
			{
				dir = WEST;
				ChangeTile(dir);
			}
			else
			{
				//TODO Message "you can't go that way"
			}
			App->commonlvls->click_A = false;
		}

		room_tile = App->level1->map[position.y][position.x];
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
		/*		
		//Look in screen the new direction
		//Look NORTH
		if (direction == 1)
		{
			compass = { 8, 0, 18, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}
		//Look WEST
		if (direction == 2)
		{
			compass = { 28, 0, 30, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}
		//Look SOUTH
		if (direction == 3)
		{
			compass = { 60, 0, 16, 25 };
			App->render->Blit(direct, 10, 10, &compass);
		}
		//Look EAST
		if (direction == 4)
		{
			compass = { 78, 0, 15, 25 };
			App->render->Blit(direct, 0, 0, &compass);
		}

		//Look Test Point TILE
//?		App->render->Blit(g_corridor, position.x + 6, position.y + 6, &test);
		*/
	}
	return UPDATE_CONTINUE;
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
		break;
	}
}
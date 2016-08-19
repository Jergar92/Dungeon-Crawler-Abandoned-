#include "ModuleMinigames.h"
#include "SDL/include/SDL.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModuleLevel1.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "GUI.h"

ModuleMinigames::ModuleMinigames()
{
	puzzle_lvl1_interact = { 0, 0, 600, 600 };
	puzzle_lvl1_info = { 0, 0, 600, 600 };
	numbers = { 0, 0, 53, 70 };
	Botton_1 = { 57, 206, 29, 29 };
	Botton_2 = { 177, 206, 29, 29 };
	Botton_3 = { 290, 206, 29, 29 };
	Botton_4 = { 403, 206, 29, 29 };
	Botton_5 = { 517, 206, 29, 29 };

}

ModuleMinigames::~ModuleMinigames()
{}

bool ModuleMinigames::Start()
{
	graphics = App->texture->Load("Puzzle_lvl1_pi.png");
	graphics_info = App->texture->Load("Puzzle_lvl1_pi_info.png");
	g_numbers = App->texture->Load("Numbers.png");

	for (int i = 0; i < 10; i++)
	{
		num[i] = 0;
	}
	puzzles_complets[0] = false;
	puzzles_complets[1] = false;
	puzzles_complets[2] = false;
	puzzles_complets[3] = false;



	return true;
}

bool ModuleMinigames::CleanUp()
{
	LOG("Unloading Level1 stage");

	return true;
}

update_status ModuleMinigames::Update()
{
	if (1)
	{
		if (puzzles_complets[0] == false)
		{
			numbers_game();
		}
		else if (puzzles_complets[1] == false)
		{

		}
		else if (puzzles_complets[2] == false)
		{

		}
		else if (puzzles_complets[3] == false)
		{

		}

	}




	return UPDATE_CONTINUE;
}



void ModuleMinigames::numbers_game()
{

	if (App->player->dir == NORTH)
	{

	}
	else if (App->player->dir == EAST)
	{
		App->render->Blit(graphics, 0, 0, &puzzle_lvl1_interact);
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (i == num[j])
				{
					int box = 0;
					if (j < 2)
					{
						box = 122 * j;
					}
					else
					{
						box = 115 * j;
					}
					if (i == 0)
					{
						numbers = {0, 0, 53, 70 };
						App->render->Blit(g_numbers, 45 + box, 315, &numbers);
					}
					else
					{
						numbers = { num[j] * 53, 0, 53, 70 };
						App->render->Blit(g_numbers, 45 + box, 315, &numbers);
					}
				}
			}
		}
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			if (App->gui->CheckButton(&Botton_1, App->input->mouse_x, App->input->mouse_y))
			{
				num[0] += 1;
				if (num[0] > 9)
				{
					num[0] = 0;
				}
			}
		}
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			if (App->gui->CheckButton(&Botton_2, App->input->mouse_x, App->input->mouse_y))
			{
				num[1] += 1;
				if (num[1] > 9)
				{
					num[1] = 0;
				}
			}
		}
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			if (App->gui->CheckButton(&Botton_3, App->input->mouse_x, App->input->mouse_y))
			{
				num[2] += 1;
				if (num[2] > 9)
				{
					num[2] = 0;
				}
			}
		}
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			if (App->gui->CheckButton(&Botton_4, App->input->mouse_x, App->input->mouse_y))
			{
				num[3] += 1;
				if (num[3] > 9)
				{
					num[3] = 0;
				}
			}
		}
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{
			if (App->gui->CheckButton(&Botton_5, App->input->mouse_x, App->input->mouse_y))
			{
				num[4] += 1;
				if (num[4] > 9)
				{
					num[4] = 0;
				}
			}
		}


	}
	else if (App->player->dir == SOUTH)
	{
		App->render->Blit(graphics_info, 0, 0, &puzzle_lvl1_info);
	}
	else if (App->player->dir == WEST)
	{
		//App->render->Blit(App->level1->test_graphics, 234, 234, &App->level1->lvl4_closed_door);
	}

	if (num[0] == 3 && num[1] == 1 && num[2] == 4 && num[3] == 1 && num[4] == 5)
	{
		puzzles_complets[0] = true;
	}


}

void ModuleMinigames::simon_game()
{




}

void ModuleMinigames::puzzle_game(){




}

void ModuleMinigames::three_line_game()
{

//	funciones(mat);

}
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

	puzzle_1 = { 0, 0, 133, 133 };
	puzzle_2 = { 133, 0, 133, 133 };
	puzzle_3 = { 266, 0, 133, 133 };
	puzzle_4 = { 0, 133, 133, 133 };
	puzzle_5 = { 133, 133, 133, 133 };
	puzzle_6 = { 266, 133, 133, 133 };
	puzzle_7 = { 0, 266, 133, 134 };
	puzzle_8 = { 133, 266, 133, 134 };
	puzzle_9 = { 266, 266, 133, 134 };

}

ModuleMinigames::~ModuleMinigames()
{}

bool ModuleMinigames::Start()
{
	graphics = App->texture->Load("Puzzle_lvl1_pi.png");
	graphics_info = App->texture->Load("Puzzle_lvl1_pi_info.png");
	g_numbers = App->texture->Load("Numbers.png");
	Puzzle = App->texture->Load("Sprite_lvl3.png");

	for (int i = 0; i < 5; i++)
	{
		num[i] = 0;
	}

	for (int i = 0, j = 8; i < 9; i++, j--)
	{
		num_puzzle[j] = i;
	}

	puzzles_complets[0] = false;
	puzzles_complets[1] = false;
	puzzles_complets[2] = false;
	puzzles_complets[3] = false;

	for (int i = 0; i < 9; i++)
	{
		isenable[i] = false;
	}

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
		/*else if (puzzles_complets[1] == false)
		{
			puzzles_complets[1] = true;
		}*/
		else if (puzzles_complets[2] == false)
		{
			puzzle_game();
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

void ModuleMinigames::puzzle_game()
{
	if (App->player->dir == NORTH)
	{

	}
	else if (App->player->dir == EAST)
	{

		for (int j = 0; j < 9; j++)
		{
			for (int i = 0; i < 9; i++)
			{
				int number_puzzle = 10;
				if (num_puzzle[j] == i)
				{
					number_puzzle = i;
				}

				if (number_puzzle != 10)
				{
					int x = 0, y = 0;
					if (j == 1)
					{
						x = 133;
					}
					if (j == 2)
					{
						x = 266;
					}
					if (j == 3)
					{
						y = 133;
					}
					if (j == 4)
					{
						x = 133;
						y = 133;
					}
					if (j == 5)
					{
						x = 266;
						y = 133;
					}
					if (j == 6)
					{
						y = 266;
					}
					if (j == 7)
					{
						x = 133;
						y = 266;
					}
					if (j == 8)
					{
						x = 266;
						y = 266;
					}

					if (number_puzzle == 0)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_1);
					}
					if (number_puzzle == 1)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_2);
					}
					if (number_puzzle == 2)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_3);
					}
					if (number_puzzle == 3)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_4);
					}
					if (number_puzzle == 4)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_5);
					}
					if (number_puzzle == 5)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_6);
					}
					if (number_puzzle == 6)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_7);
					}
					if (number_puzzle == 7)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_8);
					}
					if (number_puzzle == 8)
					{
						App->render->Blit(Puzzle, x + 100, y + 90, &puzzle_9);
					}
				}
			}
		}
		
		if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
		{

			if (App->gui->CheckButton(&puzzle_1, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[0] = true;
			}
			if (App->gui->CheckButton(&puzzle_2, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[1] = true;
			}
			if (App->gui->CheckButton(&puzzle_3, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[2] = true;
			}
			if (App->gui->CheckButton(&puzzle_4, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[3] = true;
			}
			if (App->gui->CheckButton(&puzzle_5, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[4] = true;
			}
			if (App->gui->CheckButton(&puzzle_6, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[5] = true;
			}
			if (App->gui->CheckButton(&puzzle_7, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[6] = true;
			}
			if (App->gui->CheckButton(&puzzle_8, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[7] = true;
			}
			if (App->gui->CheckButton(&puzzle_9, App->input->mouse_x - 100, App->input->mouse_y - 90))
			{
				isenable[8] = true;
			}
		}

		int j = 0;

		for (int i = 0; i < 9; i++)
		{
			if (isenable[i] == true)
			{
				j++;
				if (j > 1)
				{
					swap_1 = i;
				}
				else
				{
					swap_2 = i;
				}
			}
		}

		if (j > 1)
		{
			int temp = num_puzzle[swap_1];
			num_puzzle[swap_1] = num_puzzle[swap_2];
			num_puzzle[swap_2] = temp;
			for (int i = 0; i < 9; i++)
			{
				isenable[i] = false;
			}
		}

		
	}
	else if (App->player->dir == SOUTH)
	{

	}
	else if (App->player->dir == WEST)
	{

	}

	if (num_puzzle[0] == 0 && num_puzzle[1] == 1 && num_puzzle[2] == 2 && num_puzzle[3] == 3 && num_puzzle[4] == 4
		&& num_puzzle[5] == 5 && num_puzzle[6] == 6 && num_puzzle[7] == 7 && num_puzzle[8] == 8)
	{
		puzzles_complets[2] = true;
	}



}

void ModuleMinigames::three_line_game()
{

//	funciones(mat);

}
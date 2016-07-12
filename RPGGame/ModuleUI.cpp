#include "SDL/include/SDL.h"
#include "ModuleUI.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

ModuleUI::ModuleUI()
{
	Key_w_up = { 27, 1, 25, 26 };
	Key_q_up = { 2, 1, 26, 25 };
	Key_a_up = { 2, 26, 26, 25 };
	Key_e_up = { 51, 1, 26, 25 };
	Key_s_up = { 27, 26, 25, 25 };
	Key_d_up = { 51, 26, 26, 25 };

	Key_w_dwn = { 27, 53, 25, 26 };
	Key_q_dwn = { 2, 53, 26, 25 };
	Key_a_dwn = { 2, 78, 26, 25 };
	Key_e_dwn = { 51, 53, 26, 25 };
	Key_s_dwn = { 27, 78, 25, 25 };
	Key_d_dwn = { 51, 78, 26, 25 };
}
ModuleUI::~ModuleUI()
{}

bool ModuleUI::Start()
{
	Keys_wasd = App->texture->Load("WASD.png");
	Rect_Q = { 10, 200, 26, 25 };
	Rect_W = { 35, 200, 25, 26 };
	Rect_E = { 60, 200, 26, 25 };
	Rect_A = { 10, 225, 26, 25 };
	Rect_S = { 35, 225, 25, 25 };
	Rect_D = { 60, 225, 26, 25 };

	bool ret = true;
	LOG("Loading frontground assets");
	return ret;
}

bool ModuleUI::CleanUp()
{
	App->texture->Unload(Keys_wasd);
	LOG("Unloading Common Levels stuff");
	return true;
}

update_status ModuleUI::Update()
{
	if (myMovementState == PRES_Q)
		App->render->Blit(Keys_wasd, 10 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_q_dwn);
	else
		App->render->Blit(Keys_wasd, 10 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_q_up);
	if (myMovementState == PRES_W)
		App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_w_dwn);
	else
		App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_w_up);
	if (myMovementState == PRES_E)
		App->render->Blit(Keys_wasd, 60 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_e_dwn);
	else
		App->render->Blit(Keys_wasd, 60 * SCREEN_SIZE, 200 * SCREEN_SIZE, &Key_e_up);
	if (myMovementState == PRES_A)
		App->render->Blit(Keys_wasd, 10 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_a_dwn);
	else
		App->render->Blit(Keys_wasd, 10 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_a_up);
	if (myMovementState == PRES_S)
		App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_s_dwn);
	else
		App->render->Blit(Keys_wasd, 35 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_s_up);
	if (myMovementState == PRES_D)
		App->render->Blit(Keys_wasd, 60 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_d_dwn);
	else
		App->render->Blit(Keys_wasd, 60 * SCREEN_SIZE, 225 * SCREEN_SIZE, &Key_d_up);


	SDL_Event Event;
	bool running = true;
	while (SDL_PollEvent(&Event))
	{
		switch (Event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		}
	}
	if (Event.type == SDL_MOUSEBUTTONDOWN) // if the user clicked a mousebutton
	{
		if (App->ui->CheckButton(&App->ui->Rect_W, Event.button.x, Event.button.y))
			myMovementState = PRES_W;
		else if (App->ui->CheckButton(&App->ui->Rect_Q, Event.button.x, Event.button.y))
			myMovementState = PRES_Q;
		else if (App->ui->CheckButton(&App->ui->Rect_E, Event.button.x, Event.button.y))
			myMovementState = PRES_E;
		else if (App->ui->CheckButton(&App->ui->Rect_A, Event.button.x, Event.button.y))
			myMovementState = PRES_A;
		else if (App->ui->CheckButton(&App->ui->Rect_S, Event.button.x, Event.button.y))
			myMovementState = PRES_S;
		else if (App->ui->CheckButton(&App->ui->Rect_D, Event.button.x, Event.button.y))
			myMovementState = PRES_D;
	}
	else if (Event.type == SDL_MOUSEBUTTONUP) // if the user clicked a mousebutton
	{
		if (App->ui->CheckButton(&App->ui->Rect_W, Event.button.x, Event.button.y) && myMovementState==PRES_W)
			click_W = true;
		else if (App->ui->CheckButton(&App->ui->Rect_Q, Event.button.x, Event.button.y) && myMovementState == PRES_Q)
			click_Q = true;
		else if (App->ui->CheckButton(&App->ui->Rect_E, Event.button.x, Event.button.y) && myMovementState == PRES_E)
			click_E = true;
		else if (App->ui->CheckButton(&App->ui->Rect_A, Event.button.x, Event.button.y) && myMovementState == PRES_A)
			click_A = true;
		else if (App->ui->CheckButton(&App->ui->Rect_S, Event.button.x, Event.button.y) && myMovementState == PRES_S)
			click_S = true;
		else if (App->ui->CheckButton(&App->ui->Rect_D, Event.button.x, Event.button.y) && myMovementState == PRES_D)
			click_D = true;

		myMovementState = NONE;

	}
	return UPDATE_CONTINUE;
}

bool ModuleUI::CheckButton(const SDL_Rect* button, int x, int y) const
{
	return (x< button->x*SCREEN_SIZE + button->w*SCREEN_SIZE  && x >= button->x*SCREEN_SIZE &&
		y < button->y*SCREEN_SIZE + button->h*SCREEN_SIZE  && y >= button->y*SCREEN_SIZE);
}
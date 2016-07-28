#include "SDL/include/SDL.h"
#include "GUI_Movement.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

GUI_Movement::GUI_Movement()
{
	Key_q_up = { 2, 1, 26, 25 };
	Key_w_up = { 27, 1, 25, 26 };
	Key_e_up = { 51, 1, 26, 25 };
	Key_a_up = { 2, 26, 26, 25 };
	Key_s_up = { 27, 26, 25, 25 };
	Key_d_up = { 51, 26, 26, 25 };

	Key_q_dwn = { 2, 53, 26, 25 };
	Key_w_dwn = { 27, 53, 25, 26 };
	Key_e_dwn = { 51, 53, 26, 25 };
	Key_a_dwn = { 2, 78, 26, 25 };
	Key_s_dwn = { 27, 78, 25, 25 };
	Key_d_dwn = { 51, 78, 26, 25 };
}
GUI_Movement::~GUI_Movement()
{}

bool GUI_Movement::Start()
{
	Keys_wasd = App->texture->Load("WASD.png");
	Rect_Q = { 606, 441, 54, 54 };
	Rect_W = { 672, 441, 54, 54 };
	Rect_E = { 738, 441, 54, 54 };
	Rect_A = { 606, 507, 54, 54 };
	Rect_S = { 672, 507, 54, 54 };
	Rect_D = { 738, 507, 54, 54 };


	bool ret = true;
	LOG("Loading frontground assets");
	return ret;
}

bool GUI_Movement::CleanUp()
{
	App->texture->Unload(Keys_wasd);
	LOG("Unloading Common Levels stuff");
	return true;
}
void GUI_Movement::Retexture(){
	if (myMovementState == PRES_Q)
		App->render->Blit(Keys_wasd, 606 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_q_dwn);
	else
		App->render->Blit(Keys_wasd, 606 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_q_up);
	if (myMovementState == PRES_W)
		App->render->Blit(Keys_wasd, 672 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_w_dwn);
	else
		App->render->Blit(Keys_wasd, 672 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_w_up);
	if (myMovementState == PRES_E)
		App->render->Blit(Keys_wasd, 738 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_e_dwn);
	else
		App->render->Blit(Keys_wasd, 738 * SCREEN_SIZE, 441 * SCREEN_SIZE, &Key_e_up);
	if (myMovementState == PRES_A)
		App->render->Blit(Keys_wasd, 606 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_a_dwn);
	else
		App->render->Blit(Keys_wasd, 606 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_a_up);
	if (myMovementState == PRES_S)
		App->render->Blit(Keys_wasd, 672 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_s_dwn);
	else
		App->render->Blit(Keys_wasd, 672 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_s_up);
	if (myMovementState == PRES_D)
		App->render->Blit(Keys_wasd, 738 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_d_dwn);
	else
		App->render->Blit(Keys_wasd, 738 * SCREEN_SIZE, 507 * SCREEN_SIZE, &Key_d_up);
}
update_status GUI_Movement::Update()
{


	
	SDL_Event Event;
	bool running = true;
	Retexture();
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
		if (App->gui_movement->CheckButton(&App->gui_movement->Rect_W, Event.button.x, Event.button.y)){
			myMovementState = PRES_W;
			Retexture();
		}
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_Q, Event.button.x, Event.button.y)){
			myMovementState = PRES_Q;
			Retexture();
		}
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_E, Event.button.x, Event.button.y)){
			myMovementState = PRES_E;
			Retexture();
		}
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_A, Event.button.x, Event.button.y)){
			myMovementState = PRES_A;
			Retexture();
		}
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_S, Event.button.x, Event.button.y)){
			myMovementState = PRES_S;
			Retexture();
		}
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_D, Event.button.x, Event.button.y)){
			myMovementState = PRES_D;}
			Retexture();

	}
	else if (Event.type == SDL_MOUSEBUTTONUP) // if the user clicked a mousebutton
	{
		if (App->gui_movement->CheckButton(&App->gui_movement->Rect_W, Event.button.x, Event.button.y) && myMovementState == PRES_W)
			click_W = true;
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_Q, Event.button.x, Event.button.y) && myMovementState == PRES_Q)
			click_Q = true;
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_E, Event.button.x, Event.button.y) && myMovementState == PRES_E)
			click_E = true;
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_A, Event.button.x, Event.button.y) && myMovementState == PRES_A)
			click_A = true;
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_S, Event.button.x, Event.button.y) && myMovementState == PRES_S)
			click_S = true;
		else if (App->gui_movement->CheckButton(&App->gui_movement->Rect_D, Event.button.x, Event.button.y) && myMovementState == PRES_D)
			click_D = true;

		myMovementState = NONE;
		Retexture();

	}
	return UPDATE_CONTINUE;
}

bool GUI_Movement::CheckButton(const SDL_Rect* button, int x, int y) const
{
	return (x< button->x*SCREEN_SIZE + button->w*SCREEN_SIZE  && x >= button->x*SCREEN_SIZE &&
		y < button->y*SCREEN_SIZE + button->h*SCREEN_SIZE  && y >= button->y*SCREEN_SIZE);
}
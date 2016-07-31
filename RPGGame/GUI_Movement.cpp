#include "SDL/include/SDL.h"
#include "GUI_Movement.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleCollider.h"

GUI_Movement::GUI_Movement()
{
	Key_q_dwn = { 0, 0, 52, 52 };
	Key_w_dwn = { 52, 0, 52, 52 };
	Key_e_dwn = { 104, 0, 52, 52 };
	Key_a_dwn = { 0, 52, 52, 52 };
	Key_s_dwn = { 52, 52, 52, 52 };
	Key_d_dwn = { 104, 52, 52, 52 };
}
GUI_Movement::~GUI_Movement()
{}

bool GUI_Movement::Start()
{
	Keys_wasd = App->texture->Load("GUI_Movement.png");
	Rect_Q = { 609, 456, 52, 52 };
	Rect_W = { 675, 456, 52, 52 };
	Rect_E = { 741, 456, 52, 52 };
	Rect_A = { 609, 523, 52, 52 };
	Rect_S = { 675, 523, 52, 52 };
	Rect_D = { 741, 523, 52, 52 };


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
		App->render->Blit(Keys_wasd, 609 * SCREEN_SIZE, 456 * SCREEN_SIZE, &Key_q_dwn);
	if (myMovementState == PRES_W)
		App->render->Blit(Keys_wasd, 675 * SCREEN_SIZE, 456 * SCREEN_SIZE, &Key_w_dwn);
	if (myMovementState == PRES_E)
		App->render->Blit(Keys_wasd, 741 * SCREEN_SIZE, 456 * SCREEN_SIZE, &Key_e_dwn);
	if (myMovementState == PRES_A)
		App->render->Blit(Keys_wasd, 609 * SCREEN_SIZE, 523 * SCREEN_SIZE, &Key_a_dwn);
	if (myMovementState == PRES_S)
		App->render->Blit(Keys_wasd, 675 * SCREEN_SIZE, 523 * SCREEN_SIZE, &Key_s_dwn);
	if (myMovementState == PRES_D)
		App->render->Blit(Keys_wasd, 741 * SCREEN_SIZE, 523 * SCREEN_SIZE, &Key_d_dwn);
	
}
update_status GUI_Movement::Update()
{
 	bool running = true;
	Retexture();
	if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_DOWN) // if the user clicked a mousebutton
	{
		if (CheckButton(&App->gui_movement->Rect_W, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_W;
			Retexture();
		}
		else if (CheckButton(&App->gui_movement->Rect_Q, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_Q;
			Retexture();
		}
		else if (CheckButton(&App->gui_movement->Rect_E, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_E;
			Retexture();
		}
		else if (CheckButton(&App->gui_movement->Rect_A, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_A;
			Retexture();
		}
		else if (CheckButton(&App->gui_movement->Rect_S, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_S;
			Retexture();
		}
		else if (CheckButton(&App->gui_movement->Rect_D, App->input->mouse_x, App->input->mouse_y)){
			myMovementState = PRES_D;}
			Retexture();

	}
	else if (App->input->mouse_buttons[SDL_BUTTON_LEFT] == KEY_STATE::KEY_UP) // if the user clicked a mousebutton
	{
		if (CheckButton(&App->gui_movement->Rect_W, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_W)
			click_W = true;
		else if (CheckButton(&App->gui_movement->Rect_Q, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_Q)
			click_Q = true;
		else if (CheckButton(&App->gui_movement->Rect_E, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_E)
			click_E = true;
		else if (CheckButton(&App->gui_movement->Rect_A, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_A)
			click_A = true;
		else if (CheckButton(&App->gui_movement->Rect_S, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_S)
			click_S = true;
		else if (CheckButton(&App->gui_movement->Rect_D, App->input->mouse_x, App->input->mouse_y) && myMovementState == PRES_D)
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
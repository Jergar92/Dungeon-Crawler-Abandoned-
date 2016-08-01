#include "Application.h"
#include "GUI.h"
#include "ModuleTexture.h"
#include "ModuleRender.h"

ModuleGui::ModuleGui()
{
	background = { 0, 0, 800, 600 };
}

ModuleGui::~ModuleGui()
{}

bool ModuleGui::Start()
{
	graphics = App->texture->Load("Gui_background.png");

	return true;
}

update_status ModuleGui::Update()
{
	App->render->Blit(graphics, 0, 0, &background);

	
	return UPDATE_CONTINUE;
}

bool ModuleGui::CleanUp()
{
	App->texture->Unload(graphics);
	return true;
}

bool ModuleGui::CheckButton(const SDL_Rect* button, int x, int y) const
{
	return (x< button->x*SCREEN_SIZE + button->w*SCREEN_SIZE  && x >= button->x*SCREEN_SIZE &&
		y < button->y*SCREEN_SIZE + button->h*SCREEN_SIZE  && y >= button->y*SCREEN_SIZE);
}
bool ModuleGui::CheckButtonCircle(const Circle* button, int x, int y) const
{
	return ((button->positionX - x)*(button->positionX - x) + (button->positionY - y)*(button->positionY - y)) < button->radius*button->radius;
}
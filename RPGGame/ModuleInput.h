#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"

#define MAX_KEYS 300
#define MAX_MOUSE_BUTTONS 5
enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

	KEY_STATE GetKey(int id) const
	{
		return keyboard[id];
	}

	KEY_STATE GetMouseButton(int id) const
	{
		return mouse_buttons[id];
	}

	int GetMouseX() const
	{
		return mouse_x;
	}

	int GetMouseY() const
	{
		return mouse_y;
	}

	int GetMouseZ() const
	{
		return mouse_z;
	}

	const char* GetDroppedFile() const
	{
		return dropped_file;
	}

	bool FileWasDropped() const
	{
		if (file_was_dropped == true)
		{
			file_was_dropped = false;
			return true;
		}
		return false;
	}
public:
	KEY_STATE keyboard[MAX_KEYS];
	KEY_STATE mouse_buttons[MAX_MOUSE_BUTTONS];
	int mouse_x;
	int mouse_y;
	int mouse_z;
	char dropped_file[1024];
	mutable bool file_was_dropped;
};

#endif // __ModuleInput_H__
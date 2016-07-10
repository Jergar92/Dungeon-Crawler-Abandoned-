#include "SDL/include/SDL.h"
#include "Application.h"
#include "ModuleAudio.h"

#pragma comment(lib, "SDL_mixer/libx86/SDL2_mixer.lib")

ModuleAudio::ModuleAudio() : Module()
{
	for (uint i = 0; i < MAX_AUDIOS; ++i)
		audios[i] = nullptr;

	for (uint i = 0; i < MAX_FX; i++)
		efects[i] = nullptr;
}

ModuleAudio::~ModuleAudio(){}

bool ModuleAudio::Init()
{
	LOG("Creating audio stuf");

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		LOG("error SDLaudio")
			return false;
	}

	int flag = MIX_INIT_OGG;
	int inited_flags = Mix_Init(flag);

	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

	return true;
}

Mix_Music* const ModuleAudio::Load(const char* path)
{
	Mix_Music* audio = Mix_LoadMUS(path);

	if (audio == NULL)
	{
		LOG("Audio error, %s", Mix_GetError());
	}
	else
	{
		audios[last_audio++] = audio;
	}
	return audio;
}

Mix_Chunk* const ModuleAudio::Load_chunk(const char* path)
{
	Mix_Chunk* efect = Mix_LoadWAV(path);

	if (efect == NULL)
	{
		LOG("Audio error, %s", Mix_GetError());
	}
	else
	{
		efects[last_efect++] = efect;
	}
	return efect;
}


bool ModuleAudio::CleanUp()
{
	LOG("Destroying audio");
	for (uint i = 0; i < MAX_AUDIOS; ++i)
	{
		if (audios[i] != nullptr) Mix_FreeMusic(audios[i]);
	}
	for (uint i = 0; i < MAX_FX; ++i)
	{
		if (efects[i] != nullptr) Mix_FreeChunk(efects[i]);
	}
	Mix_CloseAudio();
	Mix_Quit();
	return true;
}
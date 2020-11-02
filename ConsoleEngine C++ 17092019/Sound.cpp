#include "Sound.h"

Sound::Sound() {};

void Sound::Play(const char* sound)
{
	PlaySound(sound, NULL, SND_ASYNC);
}

void Sound::Stop()
{
	PlaySound(NULL, NULL, SND_ASYNC);
}


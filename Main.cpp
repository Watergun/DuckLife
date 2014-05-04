#include "Classes.h"

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpSmd, int nCmdShow)
{
	GAMEFRAME NewGame;
	int r = 0;
	r = SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	if(r < 0)
	{
		ERROR_REPORT::ShowError("Main.cpp","WINAPI","WinMain","SDL_Init",SDL_GetError());
		SDL_Surface* Screen = SDL_SetVideoMode(800,600,24,SDL_HWSURFACE | SDL_DOUBLEBUF);

		Exit();
	}

	Exit();
	return 1;
}

#pragma once
#include <list>
#include <Windows.h>
#include <SDL.h>

class ERROR_REPORT
{
public:
	ERROR_REPORT() {};
	//
	static int ShowError(char* Message);
	static int ShowError(char* FileName, char* ClassName, char* FunctionName, char* Topic, char* Additional = 0);
	static int ShowError(int ErrorCode);
};

void Exit()
{
	SDL_Quit();
}



///////////////////////
class GAMESTATE
{
public:
	friend class GAMEFRAME;
	virtual int Loop(void*) = 0;
};

class GAMEFRAME
{
	std::list<GAMESTATE>GameStateList;
public:
	GAMEFRAME()	{}
	~GAMEFRAME() 
	{
		GameStateList.empty();
	}
	void HL_ADD_GAMESTATE(GAMESTATE* pGameState)
	{
		if(!pGameState)
			ERROR_REPORT::ShowError("FATAL INITIALIZING ERROR: Invalid GameState-Pointer");
		GameStateList.push_back(*pGameState);
	}
};

#ifndef CGAME_H
#define CGAME_H

#include "ErrorReport.h"
#include "CMap.h"
#include "CNPC.h"
#include "CUPC.h"

class CGame
{
//ATTRIBUTES
public:
	//The map class
	static CMap* m_pMap;

	//The player class
	static CUPC* m_pPlayer;

	//All npcs in the game
	static CNPC* m_pNpcs;

//METHODS
public:
	//Con- & Destructor
	CGame();
	~CGame();

	//The move method
	bool Move(float fTime);

	//The render method
	bool Render(float fTime);
};

#endif

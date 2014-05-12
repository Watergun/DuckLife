#include "CGame.h"

CGame::CGame()
{
	m_pMap = new CMap();
	m_pPlayer = new m_pPlayer;
	m_pNpcs = NULL;
}

CGame::~CGame()
{
	if(m_pMap != NULL)
		delete m_pMap;
	m_pMap = NULL;

	if(m_pPlayer != NULL)
		delete m_pPlayer;
	m_pPlayer = NULL;

	if(m_pNpcs != NULL)
		delete[] m_pNpcs;
	m_pNpcs = NULL;
}


bool CGame::Move(float fTime)
{
	return true;
}

bool CGame::Render(float fTime)
{
	return true;
}

#include "CSurrounding.h"

CSurrounding::CSurrounding()
{
	m_fPosX = 0.0f;
	m_fPosY = 0.0f;
}

CSurrounding::~CSurrounding()
{

}

void CSurrounding::getPosition(float& fx, float& fy)
{
	fx = m_fPosX;
	fy = m_fPosY;
}

void CSurrounding::setPosition(float fx, float fy)
{
	m_fPosX = fx;
	m_fPosY = fy;
}

#ifndef CSURROUNDING_H
#define CSURROUNDING_H

#include "CObject.h"

class CSurrounding : public CObject
{
//ATTRIBUTES
private:
	float m_fPosX;
	float m_fPosY;

//METHODS
public:
	//Con- & Destructor
	CSurrounding();
	~CSurrounding();

	//Get&Set position
	void getPosition(float& fx, float& fy);
	void setPosition(float fx, float fy);
};

#endif

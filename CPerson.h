#ifndef CPERSON_H
#define CPERSON_H

#include "CObject.h"
#include "SAttributes.h"
#include "CTool.h"

abstract class CPerson : public CObject
{
//ATTRIBUTES
private:
	int m_nPosX;
	int m_nPosY;

	char* m_cstrName;
	SAttributes m_Attributes;

	CTool* m_Inventory;

	CWeapon* m_CurrentWeapon;
//METHODS
public:
	//Con- & Destructor
	CPerson();
	~CPerson();

	//Get&Set attributes
	SAttributes* getAttributes();
	void setAttributes(SAttributes* pAttributes);

	//Get&Set position
	void getPosition(int& nx, int& ny);
	void setPosition(int nx, int ny);

	//Get&Set name
	char* getName();
	void setName(char* cstrName);

	//Get&Set current weapon
	CWeapon* getCurrentWeapon();
	void setCurrentWeapon(CWeapon* pWeapon);
};

#endif

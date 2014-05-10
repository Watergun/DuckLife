#ifndef CWEAPON_H
#define CWEAPON_H

#include "CTool.h"

abstract class CWeapon : public CTool
{
//ATTRIBUTES
private:
	float m_nDamage;

//METHODS
public:
	//Con- & Destructor
	CWeapon();
	~CWeapon();

	//Get& Set damage
	float getDamage();
	void setDamage(float fDamage);

	//Abstract method
	void Activate() = 0;
};

#endif

#ifndef CACTIVEWEAPON_H
#define CACTIVEWEAPON_H

#include "CWeapon.h"

class CActiveWeapon : public CWeapon
{
//ATTRIBUTES
private:

//METHODS
public:
	//Con- & Destructor
	CActiveWeapon();
	~CActiveWeapon();

	//Derive Activate()
	void Activate();
};

#endif

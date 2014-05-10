#ifndef CPASSIVEWEAPON_H
#define CPASSIVEWEAPON_H

#include "CWeapon.h"

class CPassiveWeapon : public CWeapon
{
//ATTRIBUTES
private:

//METHODS
public:
	//Con- & Destructor
	CPassiveWeapon();
	~CPassiveWeapon();

	//Derive Activate()
	void Activate();
};

#endif

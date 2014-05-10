#ifndef CUPC_H
#define CUPC_H

#include "CPerson.h"

class CUPC : public CPerson
{
//ATTRIBUTES
private:
	int m_nMoney;

	int m_nExperience;

//METHODS
public:
	//Con- & Destructor
	CUPC();
	~CUPC();

	//Get&Set experience
	int getExperience();
	void setExperience(int nExperience);

	//GEt&Set money
	int getMoney();
	void setMoney(int nMoney);
};

#endif

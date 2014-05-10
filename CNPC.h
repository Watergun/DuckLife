#ifndef CNPC_H
#define CNPC_H

#include "CPerson.h"

class CNPC : public CPerson
{
//ATTRIBUTES
private:
	int m_nReward;

	bool m_bFriendly;

//METHODS
public:
	//Con- & Destructor
	CNPC();
	~CNPC();

	//Get&Set reward
	int getReward();
	void setReward(int nReward);

	//Get&Set friendly
	bool getFriendly();
	void setFriendly(bool bFriendly);
};

#endif

class CUPC : public CPerson
{
//ATTRIBUTES
private:
	CTool* m_Inventory;

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

abstract class CPerson : public CObject
{
//ATTRIBUTES
private:
	int m_nPosX;
	int m_nPosY;

	char* m_cstrName;
	SAttributes m_Attributes;

//METHODS
public:
	//Con- & Destructor
	CPerson();
	~CPerson();

	//Get&Set attributes
	SAttributes* getAttributes();
	void setAttributes(SAttributes* pAttributes);

	//Get&Set position
	void getPos(int& n_x, int& n_y);
	void setPos(int n_x, int n_y);

	//Get&Set name
	char* getName();
	void setName(char* cstrName);
};

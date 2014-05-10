#include CModel.h

abstract class CObject
{
//ATTRIBUTES
public:
	//The unique identifier
	char* m_cstrIdentifier;

	//The 3D-geometry model
	CModel m_Model;

//METHODS
public:
	//Con- & Destructor
	CObject();
	virtual ~CObject();
};
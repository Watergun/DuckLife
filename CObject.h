#ifndef COBJECT_H
#define COBJECT_H

#include "ErrorReport.h"
#include "CModel.h"

class CObject
{
//ATTRIBUTES
public:
	//The unique identifier
	const char* m_cstrIdentifier;
	//And a name (useful for items or surroundings)
	const char* m_cstrName;
	//The 3D-geometry model
	CModel* m_pModel;

//METHODS
public:
	//Con- & Destructor
	CObject();
	CObject(const char* cstrModelFilename, const char* cstrIdentifier, const char* cstrName);
	virtual ~CObject();
};

#endif

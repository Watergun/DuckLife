#include "CObject.h"

CObject::CObject()
{
	m_pModel = NULL;
	m_cstrName = NULL;
	m_cstrIdentifier = "OBJECT";
}

CObject::CObject(const char* cstrModelFilename, const char* cstrIdentifier, const char* cstrName)
{
	m_pModel = new CModel();
	m_pModel->LoadData(cstrModelFilename);
	m_cstrIdentifier = cstrIdentifier;
	m_cstrName = cstrName;
}

CObject::~CObject()
{
	if(m_pModel != NULL)
		delete m_pModel;
	m_pModel = NULL;
}

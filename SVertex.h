#ifndef SVERTEX_H
#define SVERTEX_H

#ifndef NULL
#define NULL 0
#endif

#include <cstring>
#include "SVector.h"

struct SVertex
{
//
	SVertex()
	{
		m_pNormal = NULL;
	}

	SVertex(SVector3 vPosition, SVector3 vColor, SVector3* pNormal)
	{
		m_vPosition = vPosition;
		m_vColor = vColor;
		if(pNormal != NULL)
		{
			m_pNormal = new SVector3();
			memcpy(m_pNormal, pNormal, sizeof(SVector3));
		}
		else m_pNormal = NULL;
	}

	~SVertex()
	{
		if(m_pNormal != NULL)
			delete m_pNormal;
		m_pNormal = NULL;
	}

	SVector3 m_vPosition;
	SVector3 m_vColor;

	//Reference to its normal (USE WITH CAUTION)
	SVector3* m_pNormal;
};

#endif

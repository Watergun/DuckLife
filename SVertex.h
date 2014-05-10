#ifndef SVERTEX_H
#define SVERTEX_H

#include "SVector.h"

struct SVertex
{
//
	SVector3 vPosition;
	SVector3 vColor;

	//Reference to its normal
	SVector3* m_pNormal;
};

#endif

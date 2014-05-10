#ifndef CMODEL_H
#define CMODEL_H

#include "SVertex.h"
#include "SVector.h"

class CModel
{
//ATTRIBUTES
private:
	//The vertices of the model
	SVertex* m_Vertices;

	//The indices of the model
	short* m_Indices;

	//The normals of the model
	SVector3* m_Normals;

//METHODS
public:
	//Con- & Destructor
	CModel();
	~CModel();

	//Get&Set vertices/vertex
	SVertex* getVertices();
	void setVertices(SVertex* pVertices);
	SVertex* getVertex(int nIndex);
	void setVertices(SVertex* pVertex, int nBufferIndex);

	//Get&Set indices/index
	short* getIndices();
	void setIndices(short* sIndices);
	short* getIndex(int nIndex);
	void setIndex(short sIndex, int nBufferIndex);

	//Get&Set normals/normal
	SVector* getNormals();
	void setNormals(SVector* pNormals);
	SVector getNormal();
	void setNormal(SVector* pNormal);
};

#endif

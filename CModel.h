#ifndef CMODEL_H
#define CMODEL_H

#include "SVertex.h"
#include "Makros.h"
#include "SVector.h"

class CModel
{
//ATTRIBUTES
private:
	//The vertices of the model
	SVertex* m_pVertices;

	//The indices of the model
	int* m_pIndices;

	//The normals of the model
	SVector3* m_pNormals;

//METHODS
public:
	//Con- & Destructor
	CModel();
	CModel(const char* cstrFilename);
	~CModel();

	//Get&Set vertices/vertex
	SVertex* getVertices();
	void setVertices(SVertex* pVertices, int nNumber);
	SVertex* getVertex(int nPos);
	void setVertex(SVertex* pVertex, int nPos);

	//Get&Set indices/index
	int* getIndices();
	void setIndices(int* sIndices, int nNumber);
	int getIndex(int nPos);
	void setIndex(int nIndex, int nPos);

	//Get&Set normals/normal
	SVector3* getNormals();
	void setNormals(SVector3* pNormals, int nNumber);
	SVector3* getNormal(int nPos);
	void setNormal(SVector3* pNormal, int nPos);

	//Load the model data
	bool LoadData(const char* cstrFilename);

	//Public vertex-/index-/normalbuffer size
	int m_nVertexBufferSize;
	int m_nIndexBufferSize;
	int m_nNormalBufferSize;
};

#endif

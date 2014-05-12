#include "CModel.h"

//CON- & DESTRUCTOR
CModel::CModel()
{
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_pNormals = NULL;
}

CModel::CModel(const char* cstrFilename)
{
	m_pVertices = NULL;
	m_pIndices = NULL;
	m_pNormals = NULL;
	LoadData(cstrFilename);
}

CModel::~CModel()
{
	if(m_pVertices != NULL)
		delete[] m_pVertices;
	m_pVertices = NULL;

	if(m_pIndices != NULL)
		delete[] m_pIndices;
	m_pIndices = NULL;

	if(m_pNormals != NULL)
		delete[] m_pNormals;
	m_pNormals = NULL;
}

//VERTICES

SVertex* CModel::getVertices()
{
	return m_pVertices;
}

SVertex* CModel::getVertex(int pos)
{
	if(m_pVertices != NULL && pos < m_nVertexBufferSize)
	{
		return &(m_pVertices[pos]);
	}
	return NULL;
}

void CModel::setVertices(SVertex* pVertices, int nNumber)
{
	if(m_pVertices != NULL)
		delete[] m_pVertices;
	m_pVertices = new SVertex[nNumber];
	m_nVertexBufferSize = nNumber;
	memcpy(m_pVertices, pVertices, nNumber*sizeof(SVertex));
}

void CModel::setVertex(SVertex* pVertex, int pos)
{
	if(m_pVertices != NULL && pos < m_nVertexBufferSize)
	{
		memcpy(&m_pVertices[pos], pVertex, sizeof(pVertex));
	}
}

//INDICES

int* CModel::getIndices()
{
        return m_pIndices;
}

int CModel::getIndex(int pos)
{
        if(m_pIndices != NULL && pos < m_nIndexBufferSize)
        {
                return m_pIndices[pos];
        }
	return -1;
}

void CModel::setIndices(int* pIndices, int nNumber)
{
	if(m_pIndices != NULL)
		delete[] m_pIndices;
	m_pIndices = new int[nNumber];
	m_nIndexBufferSize = nNumber;
        memcpy(m_pIndices, pIndices, nNumber*sizeof(int));
}

void CModel::setIndex(int nIndex, int pos)
{
        if(m_pIndices != NULL && pos < m_nIndexBufferSize)
        {
                m_pIndices[pos] = nIndex;
        }
}

//NORMALS

SVector3* CModel::getNormals()
{
        return m_pNormals;
}

SVector3* CModel::getNormal(int pos)
{
        if(m_pNormals != NULL && pos < m_nNormalBufferSize)
        {
                return &(m_pNormals[pos]);
        }
	return NULL;
}

void CModel::setNormals(SVector3* pNormals, int nNumber)
{
	if(m_pNormals != NULL)
		delete[] m_pNormals;
	m_pNormals = new SVector3[nNumber];
	m_nNormalBufferSize = nNumber;
        memcpy(m_pNormals, pNormals, nNumber*sizeof(SVector3));
}

void CModel::setNormal(SVector3* pNormal, int pos)
{
        if(m_pNormals != NULL && pos < m_nNormalBufferSize)
        {
                memcpy(&m_pNormals[pos], pNormal, sizeof(SVector3));
	}
}

//LOADDATA

bool CModel::LoadData(const char* cstrFilename)
{
	//SUPPORT FOR .OBJ FILES
	//IN PROGRESS...

	if(cstrFilename != NULL)
		return true;
	else
		return true;
}

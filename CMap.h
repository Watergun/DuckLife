#ifndef CMAP_H
#define CMAP_H

#include "ErrorReport.h"
#include "CSurrounding.h"

class CMap
{
//ATTRIBUTES
private:
	//All Sourroundings
	CSurrounding* m_pSurroundings;

//METHODS
public:
	//Con- & Destructor
	CMap();
	~CMap();

	int m_nSize;

	//Method to load a map from a file
	bool LoadSurroundings(const char* cstrFilename);
//	bool LoadHeightMap(const char* cstrFilename);

	//Get all surroundings
	CSurrounding* getSurroundings();

	//Get a specific Surrounding object
	CSurrounding* getSurroundingObject(int nPos);
};

#endif

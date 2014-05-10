#ifndef CTOOL_H
#define CTOOL_H

#include "CObject.h"

abstract class CTool : public CObject
{
//ATTRIBUTES
private:
	//The image in the inventory
	CImage m_ItemImage;

	//The value in gold
	int m_nValue;

	//The weight
	int m_nWeight;

//METHODS
public:
	//Con- & Destructor
	CTool();
	~CTool();

	//Get&Set image
	CImage* getItemImage();
	void setItemImage(CImage* pImage);

	//Get&Set value
	int getValue();
	void setValue(int nValue);

	//Get&Set weight
	int getWeight();
	void setWeight(int nWeight);
};

#endif

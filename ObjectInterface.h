#ifndef OBJECT_INTERFACE_H
#define OBJECT_INTERFACE_H
/*OBJECT INTERFACE
Das Objekt-Interface sellt eine allgemeine Form eines dreidimensionalen Objektes dar.
Es besitzt eine abstrakte Methode (void Derive), die allein der Kenntlichmachung der
Vererbung dient.
Das Objekt-Interface besitzt zwei Attribute:
	-Das Model, das die Daten enthaelt (TriBaseModel .tbm)
	-Ein Name
*/
#include <TriBase.h>
#define MESH_TYPE tbModel

class OI
{
public:
	OI()
	{
		if(!m_pObjectModel)
			m_pObjectModel = new tbModel;
	}
	virtual ~OI()
	{
		if(m_pObjectModel != NULL)
			delete m_pObjectModel;
		m_pObjectModel = NULL;
	}
	//Die abstrakte Methode die leer ueberschrieben werden kann
	virtual void Derive() = 0;
	//Get
	MESH_TYPE* GetModel()	{return m_pObjectModel;}
	//Set
	void SetModel(MESH_TYPE* pModel) {m_pObjectModel = pModel;}
	//Attribute
protected:
	//Objektbezeichner
	char*			m_sOID;
	//Objektdaten
	MESH_TYPE*			m_pObjectModel;
	//
};

#endif

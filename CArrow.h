#ifndef CARROW_H
#define CARROW_H

/*CLASS DESCRIPTION [DE]
KLASSE CARROW
Die Klasse CArrow stellt ein sich bewegendes Objekt im Raum
dar. Sie erbt von ObjektInterface, weshalb ihr ein Modell
zugeschrieben werden kann.
Die Klasse besitzt Methoden, um die Bewegung des Modells
im Raum zu berechnen. Dabei exisitiert die Moeglichkeit,
die Bewegung unter Einfluss des Luftwiderstands zu berechnen
Entscheidend bei der Berechnung der Objekte ist der Einfluss
der Gravitation auf die Flugbahn und Gewschwindigkeit. Hinzu
kaeme die Moeglichkeit, den Luftwiderstand einzukalkulieren.
(Air Friction Computing = AFC)
Die Klasse CArrow wird mit der Init Methode initialisiert.
InitAFC initialisiert die Luftwiderstandsberechnung.

*/

#include "CObject.h"

//Die KLasse hat als internen Winkeltyp das Gradmaß
//Jedoch kann  der Aufrufer selbst entscheiden welchen Typ
//er initialisiert und spaeter als Ausgabe bekommt
enum ANGLETYPE {DEG, RAD};	//-> entspricht dem (externen) gewuenschten Winkeltyp

class CArrow : public CObject
{
public:
	//Konstruktor und Destruktor entsprechen der Oberklasse
	CArrow()
	{
		if(!m_pModel)
			m_pModel = new CModel;
	}

	~CArrow()
	{
		if(m_pModel != NULL)
			delete m_pModel;
		m_pModel = NULL;
	}

	//Die normale Initialisierungsmethode
	void Init(float fGravity,
		  float fStartVelocity,
		  float fStartAngleUD,
		  float StartAngleLR,
		  ANGLETYPE AType,
		  char* pcModelFilename,
		  SVector3 vStartPos = SVector3(0.0f,0.0f,0.0f),
		  BOOL bAirFrictionComputing = FALSE);

	//Fuer die Luftwiederstandsberechnungen
	void InitAFC(float fEnvironmentDensity,
		     float fFrontalSurface,
		     float AerodynamicValue,
		     float fMass);

	//Berechnet die neue Geschwindigkeit und Position
	void		CalcPos(float fNumSecsPassed);

	//Richtung
	SVector3	GetDirection()	{return SVector3Normalize(m_vDirection);}

	//Position
	SVector3	GetPosition()	{return m_vPosition;}

	//Winkelangaben in der Klasse
	float		GetUDAngle()
		{return ((m_AT == RAD) ? m_fFlyingAngleUD : RAD_TO_DEG(m_fFlyingAngleUD));}
	float		GetLRAngle()
		{return ((m_AT == RAD) ? m_fFlyingAngleLR : RAD_TO_DEG(m_fFlyingAngleLR));}
private:
	//KLassenattribute
	//Die Geschwindigkeiten (gesamt,X,Y,Z)
	float			m_fVelocity;
	float			m_fVelocityX;
	float			m_fVelocityY;
	float			m_fVelocityZ;
	//Dier beiden Winkel (oben-unten, rechts-links)
	float			m_fFlyingAngleUD;
	float			m_fFlyingAngleLR;
	//Position und Richtung
	SVector3		m_vPosition;
	SVector3		m_vDirection;
	//Betrag der Gravitation
	float			m_fGravity;
	//Extern(!) gewuenschter Winkeltyp
	ANGLETYPE		m_AT;
	//AFC (Air Friction Computing)
	bool m_bAFC;
	bool m_bInitialized;
	bool m_bInitializedAFC;
	//
	float			m_f_Rho_A_W_05_Value;
	float			m_fMass;
};

#endif

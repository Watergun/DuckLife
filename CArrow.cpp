#include "CArrow.h"

//Initialisierung
void CArrow::Init(float fGravity,
				  float fStartVelocity,
				  float fStartAngleUD,
				  float fStartAngleLR,
				  ANGLETYPE AType,
				  char* pcModelFilename,
				  SVector3 vStartPos,
				  BOOL bAirFrictionComputing)
{
	//Uebernahme der Parameter
	m_bInitialized = true;
	m_fGravity						= fGravity;
	m_bAFC							= (bool)bAirFrictionComputing;
	if(m_fGravity > 0)	m_fGravity *= -1;	//Gravitation muss negativ sein
	m_vPosition						= vStartPos;
	m_fVelocity						= fStartVelocity;
	if(m_fVelocity == 0.0f)m_fVelocity = 0.1f;
	m_fFlyingAngleUD = (AType == RAD) ? fStartAngleUD : DEG_TO_RAD(fStartAngleUD);
	m_fFlyingAngleLR = (AType == RAD) ? fStartAngleLR : DEG_TO_RAD(fStartAngleLR);
	m_AT = AType;
	m_sOID = "ARROW";
	//
	if(!m_pModel) m_pModel = new CModel;
	m_pModel->LoadData(pcModelFilename);
	//Berechnung der X Y und Z Geschwindigkeit
	m_fVelocityY		= m_fVelocity * sinf(m_fFlyingAngleUD);			//V[Y] !
	m_fVelocityZ		= m_fVelocity * cosf(m_fFlyingAngleLR);			//V[Z] !
	m_fVelocityX		= m_fVelocity * sinf(m_fFlyingAngleLR);			//V[X] !
	m_vDirection		= SVector3(m_fVelocityX,m_fVelocityY,m_fVelocityZ);
	//Sinus- und Kosinusberechnungen können, ganz leicht gerundet, ungenau werden!
	//[Funktionalitaet fraglich]
#ifdef DEBUG
	double SQV = m_fVelocity * m_fVelocity;
	double SQVX = m_fVelocityX * m_fVelocityX;
	double SQVY = m_fVelocityY * m_fVelocityY;
	double SQVZ = m_fVelocityZ * m_fVelocityZ;
	double Imprecision = (SQVX + SQVY + SQVZ) - SQV;
	if(Imprecision < 0) Imprecision *= -1;
	m_dImprecision += Imprecision;
#endif
}

//Initialisiere Air Friction Computing (AFC)
void CArrow::InitAFC(float fEnvironmentDensity,
					float fFrontalSurface,
					float fAerodynamicValue,
					float fMass)
{
	m_bInitializedAFC = true;
	m_f_Rho_A_W_05_Value = 0.5f * fFrontalSurface * fAerodynamicValue * fEnvironmentDensity;
	m_fMass = fMass;
}
//
//Berechnung
void CArrow::CalcPos(float fNumSecsPassed)
{
	if(!m_bInitialized)
		return;
	//Zuerst neue Position berechnen (Vorherige Geschwindigkeit)
	SVector3 DeltaPosition = m_vDirection * fNumSecsPassed;
	m_vPosition += DeltaPosition;
	//Und dann den neuen Up-Down-Winkel berechnen (Wird von Gravitation beeinflusst)
	m_fVelocityY += (m_fGravity * fNumSecsPassed);
	double SQVX = m_fVelocityX * m_fVelocityX;
	double SQVY = m_fVelocityY * m_fVelocityY;
	double SQVZ = m_fVelocityZ * m_fVelocityZ;
	m_fVelocity = (float)sqrt(SQVX + SQVY + SQVZ);
	m_fFlyingAngleUD = asinf(m_fVelocityY / m_fVelocity);
	//Der neue Kurs
	m_vDirection = SVector3(m_fVelocityX, m_fVelocityY, m_fVelocityZ);
//
	if(m_bAFC && m_bInitializedAFC)
	{
		//Gravitation Aendern - der Rest (in Y-Richtung !) wird oben erledigt
		float AFForceZ = m_f_Rho_A_W_05_Value * m_fVelocityZ * m_fVelocityZ;
		if(AFForceZ < 0) AFForceZ *= -1;
		float fAccelZ = AFForceZ / m_fMass;
		m_fVelocityZ -= fAccelZ * fNumSecsPassed;
		//X und Y Richtung sind eigentlich nicht zu vernachlaessigen
		//Jedoch wird der hier Wert auf die Z-Geschwindigkeit gelegt
		//Weiterhin koennte die Y-Geschwindigkeit auch von grosser Bedeutung sein
		//X-Richtung bleibt unbeeinflusst
		m_vDirection.z = m_fVelocityZ;
	}
}

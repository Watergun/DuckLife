#ifndef SVECTOR_H
#define SVECTOR_H

struct SVector3
{
	float m_f1;
	float m_f2;
	float m_f3;

	SVector3 operator + (SVector3 vec)
	{
		return {(m_f1 + vec.m_f1),
			(m_f2 + vec.m_f2),
			(m_f3 + vec.m_f3)};
	}

	SVector3 operator * (float fScale)
	{
		return {(m_f1 * fScale),
			(m_f2 * fScale),
			(m_f3 * fScale)};
	}

	SVector3 operator - (SVector3 vec);
	{
		return {(m_f1 - vec.m_f1),
			(m_f2 - vec.m_f2),
			(m_f3 - vec.m_f3)};
	}

	SVector3 operator / (float fScale);
	{
		return {(m_f1 / fScale),
			(m_f2 / fScale),
			(m_f3 / fScale)};
	}
};

struct SVector2
{
	float m_f1;
	float m_f2;

	SVector2 operator + (SVector2 vec);
	{
		return {(m_f1 + vec.m_f1),(m_f2 + vec.m_f2)};
	}

	SVector2 operator * (float fScale);
	{
		return {(m_f1 * fScale), (m_f2 * fScale)};
	}

	SVector2 operator - (SVector2 vec);
	{
		return {(m_f1 - vec.m_f1), (m_f2 - vec.m_f2)};
	}

	SVEctor2 operator / (float fScale)
	{
		return {(m_f1 / fScale), (m_f2 / fScale)};
	}
};

float SVector2Point(SVector2* vec1, SVector2* vec2)
{
	return (vec1.m_f1 * vec2.m_f1 +
		vec1.m_f2 * vec2.m_f2);
}

float SVector3Point(SVector3 vec1, SVector3 vec2)
{
	return (vec1.m_f1 * vec2.m_f1 +
		vec1.m_f2 * vec2.m_f2 +
		vec1.m_f3 * vec2.m_f3);
}

SVector3 SVector3Cross(SVector2 vec1, SVector2 vec2)
{
	return {(vec1.m_f2 * vec2.m_f3 - vec1.m_f3 * vec2.m_f2),
		(vec1.m_f3 * vec2.m_f1 - vec1.m_f1 * vec2.m_f3),
		(vec1.m_f1 * vec2.m_f2 - vec1.m_f2 * vec2.m_f1)};
}

#endif

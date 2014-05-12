#ifndef SVECTOR_H
#define SVECTOR_H

struct SVector3
{
	float m_f1;
	float m_f2;
	float m_f3;

	SVector3()
	{}

	SVector3(float f1, float f2, float f3)
	{
		m_f1 = f1;
		m_f2 = f2;
		m_f3 = f3;
	}

	const SVector3 operator+(SVector3 const& vec)
	{
		return SVector3((m_f1 + vec.m_f1),
			(m_f2 + vec.m_f2),
			(m_f3 + vec.m_f3));
	}

	const SVector3 operator * (float const& fScale)
	{
		return SVector3((m_f1 * fScale),
			(m_f2 * fScale),
			(m_f3 * fScale));
	}

	const SVector3 operator - (SVector3 const& vec)
	{
		return SVector3((m_f1 - vec.m_f1),
			(m_f2 - vec.m_f2),
			(m_f3 - vec.m_f3));
	}

	const SVector3 operator / (float const& fScale)
	{
		return SVector3((m_f1 / fScale),
			(m_f2 / fScale),
			(m_f3 / fScale));
	}
};

struct SVector2
{
	float m_f1;
	float m_f2;

	SVector2()
	{}

	SVector2(float f1, float f2)
	{
		m_f1 = f1;
		m_f2 = f2;
	}

	const SVector2 operator + (SVector2 const& vec)
	{
		return SVector2((m_f1 + vec.m_f1),(m_f2 + vec.m_f2));
	}

	const SVector2 operator * (float const& fScale)
	{
		return SVector2((m_f1 * fScale), (m_f2 * fScale));
	}

	const SVector2 operator - (SVector2 const& vec)
	{
		return SVector2((m_f1 - vec.m_f1), (m_f2 - vec.m_f2));
	}

	const SVector2 operator / (float const& fScale)
	{
		return SVector2((m_f1 / fScale), (m_f2 / fScale));
	}
};

inline float SVector2Point(SVector2& vec1, SVector2& vec2)
{
	return (vec1.m_f1 * vec2.m_f1 + vec1.m_f2 * vec2.m_f2);
}

inline float SVector3Point(SVector3& vec1, SVector3& vec2)
{
	return ((vec1.m_f1 * vec2.m_f1) + (vec1.m_f2 * vec2.m_f2) + (vec1.m_f3 * vec2.m_f3));
}

inline SVector3 SVector3Cross(SVector3& vec1, SVector3& vec2)
{
	return SVector3((vec1.m_f2 * vec2.m_f3 - vec1.m_f3 * vec2.m_f2),
		(vec1.m_f3 * vec2.m_f1 - vec1.m_f1 * vec2.m_f3),
		(vec1.m_f1 * vec2.m_f2 - vec1.m_f2 * vec2.m_f1));
}

#endif

#ifndef INFOMESSAGE_H
#define INFOMESSAGE_H

#include <cstdlib>
#include <iostream>

class INFORMATION_MESSAGE
{
public:
	INFORMATION_MESSAGE();

	static void InfoMessage(const char* Message);
	static void InfoMessage(const char* Message, const char* Object);
	static void InfoMessage(int Value);
	static void InfoMessage(float Value);
	static void InfoMessage(const char* Message, int Value);
	static void InfoMessage(const char* Message, float Value);
};

inline void INFO_MSG(const char* MSG)
{
	INFORMATION_MESSAGE::InfoMessage(MSG);
}

inline void INFO_MSG(const char* MSG, const char* OBJ)
{
	INFORMATION_MESSAGE::InfoMessage(MSG,OBJ);
}

inline void INFO_MSG(int VAL)
{
	INFORMATION_MESSAGE::InfoMessage(VAL);
}

inline void INFO_MSG(float VAL)
{
	INFORMATION_MESSAGE::InfoMessage(VAL);
}

inline void INFO_MSG(const char* MSG, int VAL)
{
	INFORMATION_MESSAGE::InfoMessage(MSG,VAL);
}

inline void INFO_MSG(const char* MSG, float VAL)
{
        INFORMATION_MESSAGE::InfoMessage(MSG,VAL);
}

#endif

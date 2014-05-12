#include "InfoMessage.h"

INFORMATION_MESSAGE::INFORMATION_MESSAGE()
{}

void INFORMATION_MESSAGE::InfoMessage(const char* Message)
{
	std::cout << "[INFO] " << Message << std::endl;
}

void INFORMATION_MESSAGE::InfoMessage(const char* Message, const char* Object)
{
	std::cout << "[INFO] " << Message << " : " << Object << std::endl;
}

void INFORMATION_MESSAGE::InfoMessage(int Value)
{
	std::cout << "[INFO]: " << Value << std::endl;
}

void INFORMATION_MESSAGE::InfoMessage(float Value)
{
        std::cout << "[INFO]: " << Value << std::endl;
}

void INFORMATION_MESSAGE::InfoMessage(const char* Message, int Value)
{
        std::cout << "[INFO]: " << Message << " : " << Value << std::endl;
}

void INFORMATION_MESSAGE::InfoMessage(const char* Message, float Value)
{
        std::cout << "[INFO]: " << Message << " : " << Value << std::endl;
}

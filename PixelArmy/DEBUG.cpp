#include "DEBUG.h"



DEBUG::DEBUG()
{
}


DEBUG::~DEBUG()
{
}

void DEBUG::Log(std::string aMessage)
{
	std::cout << aMessage << std::endl;
}

void DEBUG::Log(float aMessage)
{
	std::cout << aMessage << std::endl;
}

#pragma once

#include <iostream>
#include <string>

class DEBUG
{
public:
	DEBUG();
	~DEBUG();

	static void Log(std::string aMessage);
	static void Log(float aMessage);
};


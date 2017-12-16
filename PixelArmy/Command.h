#pragma once

#include "Player.h"

class Command
{
public:
	virtual ~Command();
	virtual void Execute(Player* const aPlayer) = 0;
protected:
	CityRegion myRegion;
};


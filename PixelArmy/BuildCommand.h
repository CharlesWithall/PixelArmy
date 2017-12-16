#pragma once
#include "Command.h"

class BuildCommand : public Command
{
public:
	BuildCommand(CityRegion aRegion);
	~BuildCommand();
	void Execute(Player* const aPlayer) override;
};

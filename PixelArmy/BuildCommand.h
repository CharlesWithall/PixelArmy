#pragma once
#include "Command.h"

class BuildCommand : public Command
{
public:
	BuildCommand();
	~BuildCommand();
	void Execute(Player* const aPlayer);
};

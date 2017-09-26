#include "BuildCommand.h"



BuildCommand::BuildCommand()
{
}


BuildCommand::~BuildCommand()
{
}

void BuildCommand::Execute(Player* const aPlayer)
{
	aPlayer->BuildBuilding();
}

#include "BuildCommand.h"



BuildCommand::BuildCommand(CityRegion aRegion)
{
	myRegion = aRegion;
}


BuildCommand::~BuildCommand()
{
}

void BuildCommand::Execute(Player* const aPlayer)
{
	aPlayer->BuildBuilding(myRegion);
}

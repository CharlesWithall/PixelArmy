#include "Building.h"
#include "Player.h"
#include "CoordinateDefinitions.h"

Building::Building(Player* const aPlayer, const sf::Texture& aTexture, const CityRegion& aRegion) :
	GameEntity(aTexture, aPlayer->GetWorldModel()->GetCoordinates()->GetBuildingLocationAt(aRegion)),
	myPlayer(aPlayer),
	myCityRegion(aRegion),
	mySpawnSpeed(10.f),
	myBattalionSize(2)
{
	mySoldierPrototype = new Soldier(aPlayer);
	mySoldierPrototype->SetIsActive(false);
}


Building::~Building()
{
}

void Building::Update(const float& aTimeElapsed)
{
	if (WaitForSeconds(mySpawnSpeed, aTimeElapsed))
		SpawnBattalion();
}


void Building::SpawnBattalion()
{
	DEBUG::Log("Spawn Battalion");
	for (int i = 0; i < myBattalionSize; ++i)
	{
		int locationY = GetYCoordinateToSpawnSoldier(i + 1, myBattalionSize);
		Soldier* newSoldier = myPlayer->GetRecycledSoldier(mySoldierPrototype, locationY);

		if (!newSoldier)
		{
			newSoldier = new Soldier(myPlayer, mySoldierPrototype, locationY);
			myPlayer->RegisterSoldier(newSoldier);
		}
	}
}

int Building::GetYCoordinateToSpawnSoldier(const int& anIndex, const int& aMaxIndex)
{
	int barSize = myPlayer->GetWorldModel()->GetCoordinates()->GetBattleBarHeight();
	int location = (barSize * anIndex) / (aMaxIndex + 1);
	return (location + myPlayer->GetWorldModel()->GetCoordinates()->GetTopOfBattleBarY());
}
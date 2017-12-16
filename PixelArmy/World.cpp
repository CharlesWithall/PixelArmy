#include "World.h"



World::World(const PlayerID& aPlayerID, const sf::Vector2f& aScalingVector)
{
	myAssetPool = new AssetPool();
	myBackgroundBuilder = new BackgroundBuilder();
	myBackgroundBuilder->CreateBackground(myAssetPool->GetBackgroundTexture());
	myCoordinateDefinitions = new CoordinateDefinitions(aPlayerID, aScalingVector);
}


World::~World()
{
}

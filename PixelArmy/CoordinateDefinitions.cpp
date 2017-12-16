#include "CoordinateDefinitions.h"
#include "DEBUG.h"
#include "World.h"

CoordinateDefinitions::CoordinateDefinitions(const PlayerID& aPlayerID, const sf::Vector2f& aScalingVector) : myScalingVector(aScalingVector)
{
	InitBattleBar(aPlayerID);
	InitBuildingLocations(aPlayerID);
}


CoordinateDefinitions::~CoordinateDefinitions()
{
}

sf::Vector2f CoordinateDefinitions::GetBuildingLocationAt(const CityRegion& aRegion)
{
	int index = (int)aRegion;

	if (index > myBuildingLocations.size())
	{
		DEBUG::Log("Can't get building at location. Region Out of bounds of array");
		return sf::Vector2f(0, 0);
	}

	return myBuildingLocations[index];
}

void CoordinateDefinitions::InitBattleBar(const PlayerID& aPlayerID)
{
	myBattleBarTopY = ScaleFloat(56.f, myScalingVector.y);
	myBattleBarBottomY = ScaleFloat(254.f, myScalingVector.y);

	switch (aPlayerID)
	{
	case PlayerID::PlayerOne:
		myBacklineX = ScaleFloat(625.f, myScalingVector.x);
		break;
	case PlayerID::PlayerTwo:
		myBacklineX = ScaleFloat(1315.f, myScalingVector.x);
		break;
	}
	
}

void CoordinateDefinitions::InitBuildingLocations(const PlayerID& aPlayerID)
{
	myBuildingLocations = std::vector<sf::Vector2f>();

	switch (aPlayerID)
	{
	case PlayerID::PlayerOne:
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(160.f, 400.f))); // North-West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(380.f, 400.f))); // North
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(600.f, 400.f))); // North-East
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(160.f, 620.f))); // West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(380.f, 620.f))); // Central
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(600.f, 620.f))); // East
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(160.f, 840.f))); // South-West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(380.f, 840.f))); // South
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(600.f, 840.f))); // South-East
		break;
	case PlayerID::PlayerTwo:
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1180.f, 400.f))); // North-West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1400.f, 400.f))); // North
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1620.f, 400.f))); // North-East
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1180.f, 620.f))); // West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1400.f, 620.f))); // Central
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1620.f, 620.f))); // East
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1180.f, 840.f))); // South-West
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1400.f, 840.f))); // South
		myBuildingLocations.push_back(ScaleVector(sf::Vector2f(1620.f, 840.f))); // South-East
		break;
	default:
		DEBUG::Log("Invalid Player passed into CoordinateDefinitions::InitBuildingLocations!!!");
	}
	
}
#pragma once

#include "World.h"
#include <vector>

class Building;
class Soldier;

class Player
{
public:
	Player(PlayerID aPlayerID, const sf::Vector2f aScalingVector);
	~Player();
	
	void BuildBuilding(const CityRegion& aRegion);
	void RegisterSoldier(Soldier* const aSoldier);

	World* const GetWorldModel() { return myWorld; }
	const PlayerID& GetPlayerID() { return myPlayerID; }
	const int GetFrontlineCoordinate();
	const int GetBacklineCoordinate() { return myBacklineXCoordinate; }
	Soldier* const GetClosestSoldierTo(const sf::Vector2f& aPoint);
	Soldier* GetRecycledSoldier(Soldier* aPrototypeSoldier, const int& aYPosition);

private:

	World* myWorld;
	Player* myEnemy;

	std::vector<Building*> myBuildings;
	std::vector<Soldier*> mySoldiers;

	int myCityHealth;

	int myFrontlineXCoordinate;
	int myBacklineXCoordinate;

	float myCooldownBar;

	PlayerID myPlayerID;
};


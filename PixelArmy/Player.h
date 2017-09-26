#pragma once

#include "Building.h"
#include "Soldier.h"
#include <vector>

enum PlayerID
{
	PlayerOne,
	PlayerTwo
};

class Player
{
public:
	Player();
	~Player();
	
	void BuildBuilding();
	const PlayerID& const GetPlayerID() { return myPlayerID; }
private:
	std::vector<Building*> myBuildings;
	std::vector<Soldier*> myActiveSoldiers;
	const int myBacklineXCoordinate;
	const bool isMarchingRight;
	int myCityHealth;
	int myFrontlineXCoordinate;
	float myCooldownBar;
	PlayerID myPlayerID;
};


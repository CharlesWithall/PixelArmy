#pragma once

#include "Player.h"

class Player_Shared
{
public:
	Player_Shared(Player* aPlayerOne, Player* aPlayerTwo);
	~Player_Shared();

	int GetFrontlineLocation();
	int GetEnemyBacklineLocation(const PlayerID& aPlayerID);
	Soldier* const GetClosestEnemySoldierTo(const sf::Vector2f& aPoint, const PlayerID& aPlayerID);
private:
	Player* myPlayerOne;
	Player* myPlayerTwo;
};


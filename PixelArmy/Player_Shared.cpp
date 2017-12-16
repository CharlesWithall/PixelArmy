#include "Player_Shared.h"

Player_Shared::Player_Shared(Player* aPlayerOne, Player* aPlayerTwo) :
	myPlayerOne(aPlayerOne),
	myPlayerTwo(aPlayerTwo)
{

}


Player_Shared::~Player_Shared()
{
}

int Player_Shared::GetFrontlineLocation()
{
	int playerOneFrontline = myPlayerOne->GetFrontlineCoordinate();
	int playerTwoFrontline = myPlayerTwo->GetFrontlineCoordinate();

	if (playerOneFrontline >= playerTwoFrontline)
		return (playerOneFrontline + playerTwoFrontline) * 0.5f;

	return 0;
}

Soldier* const Player_Shared::GetClosestEnemySoldierTo(const sf::Vector2f& aPoint, const PlayerID& aPlayerID)
{
	switch (aPlayerID)
	{
	case PlayerID::PlayerOne:
		return myPlayerTwo->GetClosestSoldierTo(aPoint);
	case PlayerID::PlayerTwo:
		return myPlayerOne->GetClosestSoldierTo(aPoint);
	}

	return nullptr;
}

int Player_Shared::GetEnemyBacklineLocation(const PlayerID& aPlayerID)
{
	switch (aPlayerID)
	{
	case PlayerID::PlayerOne:
		return myPlayerTwo->GetBacklineCoordinate();
	case PlayerID::PlayerTwo:
		return myPlayerOne->GetBacklineCoordinate();
	}

	return -1;
}
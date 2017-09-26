#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
	for (auto building : myBuildings)
	{
		delete building;
	}
}

void Player::BuildBuilding()
{
	Building* newBuilding = new Building();
	myBuildings.push_back(newBuilding);
}
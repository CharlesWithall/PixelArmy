#include "Player.h"
#include "Building.h"
#include "Soldier.h"

Player::Player(PlayerID aPlayerID, const sf::Vector2f aScalingVector) : myPlayerID(aPlayerID)
{
	myWorld = new World(aPlayerID, aScalingVector);
}


Player::~Player()
{
	for (auto building : myBuildings)
	{
		if (building)
			delete building;
	}

	delete myWorld;
}

void Player::BuildBuilding(const CityRegion& aRegion)
{
	sf::Texture* buildingTex = myWorld->GetAsset()->GetBuildingTexture();
	Building* newBuilding = new Building(this, *buildingTex, aRegion);
	myBuildings.push_back(newBuilding);
}

void Player::RegisterSoldier(Soldier* const aSoldier)
{
	mySoldiers.push_back(aSoldier);
}

const int Player::GetFrontlineCoordinate()
{
	int frontlineCoordinate = 0;

	switch (myPlayerID)
	{
	case PlayerID::PlayerOne:
		for (Soldier* soldier : mySoldiers)
		{
			if (soldier->GetPosition().x > frontlineCoordinate)
				frontlineCoordinate = soldier->GetPosition().x;
		}

		return frontlineCoordinate;
	case PlayerID::PlayerTwo:
		frontlineCoordinate = INT_MAX;

		for (Soldier* soldier : mySoldiers)
		{
			if (soldier->GetPosition().x < frontlineCoordinate)
				frontlineCoordinate = soldier->GetPosition().x;
		}

		return frontlineCoordinate;
	default:
		DEBUG::Log("Invalid Player Selected in GetFrontlineCoordinate Function");
		return frontlineCoordinate;
	}
}

Soldier* const Player::GetClosestSoldierTo(const sf::Vector2f& aPoint)
{
	Soldier* returnSoldier = nullptr;
	float closestDistance = FLT_MAX;

	for (Soldier* soldier : mySoldiers)
	{
		if (!soldier->GetIsActive())
			continue;

		int xDist = abs(soldier->GetPosition().x - aPoint.x);
		int yDist = abs(soldier->GetPosition().y - aPoint.y);
		float totalDistance = sqrt(pow(xDist,2) + pow(yDist,2));

		if (totalDistance < closestDistance)
		{
			closestDistance = totalDistance;
			returnSoldier = soldier;
		}
	}

	return returnSoldier;
}

Soldier* Player::GetRecycledSoldier(Soldier* aPrototypeSoldier, const int& aYPosition)
{
	for (Soldier* soldier : mySoldiers)
	{
		if (!soldier->GetIsActive())
		{
			soldier->Recycle(aPrototypeSoldier, aYPosition);
			return soldier;

		}
	}

	return nullptr;
}
#pragma once

#include "DEBUG.h"
#include "GameEntity.h"
#include "Soldier.h"

enum CityRegion;
class Player;

class Building : public GameEntity
{
public:
	Building(Player* const aPlayer, const sf::Texture& aTexture, const CityRegion& aRegion);
	~Building();

	void Update(const float& aTimeElapsed) override;
	void SpawnBattalion();
private:
	int GetYCoordinateToSpawnSoldier(const int& anIndex, const int& aMaxIndex);
	Soldier* FindRecyclableSoldier();

	Soldier* mySoldierPrototype;
	int myBattalionSize;
	float mySpawnSpeed;
	Player* const myPlayer;
	const CityRegion myCityRegion;
};


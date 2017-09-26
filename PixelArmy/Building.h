#pragma once

#include <SFML/Graphics.hpp>
#include "Soldier.h"

class Building
{
public:
	Building();
	~Building();
private:
	Soldier mySoldierPrototype;
	sf::Vector2f myLocation;
	int myNumberOfSoldiersSpawned;
	float mySpawnSpeed;
};


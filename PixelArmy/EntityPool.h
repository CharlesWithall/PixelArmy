#pragma once

#include "DEBUG.h"
#include "Player_Shared.h"
#include <SFML/Graphics.hpp>
#include <vector>

class GameEntity;

class EntityPool
{
public:
	static void RenderAll(sf::RenderWindow* aWindow);
	static void UpdateAll(Player_Shared* aPlayerSharedData, const float& aTimeElapsed);
	static std::vector<GameEntity*> ourEntityPool;
private:
	sf::RenderWindow* myWindow;
};


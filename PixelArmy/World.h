#pragma once

#include <SFML/Graphics.hpp>
#include "AssetPool.h"
#include "BackgroundBuilder.h"
#include "CoordinateDefinitions.h"

enum PlayerID
{
	PlayerOne,
	PlayerTwo
};

enum CityRegion
{
	NORTHWEST,
	NORTH,
	NORTHEAST,
	WEST,
	CENTRAL,
	EAST,
	SOUTHWEST,
	SOUTH,
	SOUTHEAST,
	INVALID
};

class World
{
public:
	World(const PlayerID& aPlayerID, const sf::Vector2f& aScalingVector);
	~World();

	AssetPool* GetAsset() { return myAssetPool; }
	CoordinateDefinitions* GetCoordinates() { return myCoordinateDefinitions; }
private:
	AssetPool* myAssetPool;
	BackgroundBuilder* myBackgroundBuilder;
	CoordinateDefinitions* myCoordinateDefinitions;
};


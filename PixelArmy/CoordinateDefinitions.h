#pragma once
#include <SFML/Graphics.hpp>

enum CityRegion;
enum PlayerID;

/// ALL COORDINATES THAT ARE USED SHOULD BE SCALED TO SCREEN SIZE ON INIT
class CoordinateDefinitions
{
public:
	CoordinateDefinitions(const PlayerID& aPlayerID, const sf::Vector2f& aScalingVector);
	~CoordinateDefinitions();

	int GetTopOfBattleBarY() { return myBattleBarTopY; }
	int GetBottomOfBattleBarY() { return myBattleBarBottomY; }
	int GetBackline() { return myBacklineX; }
	int GetBattleBarHeight() { return myBattleBarBottomY - myBattleBarTopY; }
	sf::Vector2f GetBuildingLocationAt(const CityRegion& aRegion);
private:
	void InitBattleBar(const PlayerID& aPlayerID);
	void InitBuildingLocations(const PlayerID& aPlayerID);

	const sf::Vector2f ScaleVector(const sf::Vector2f& aVector) { return sf::Vector2f(aVector.x * myScalingVector.x, aVector.y * myScalingVector.y); }
	const float ScaleFloat(const float& aFloat, const float& aScaleValue) { return aFloat * aScaleValue; }

	sf::Vector2f myScalingVector;

	int myBattleBarTopY;
	int myBattleBarBottomY;
	float myBacklineX;

	std::vector<sf::Vector2f> myBuildingLocations;
};


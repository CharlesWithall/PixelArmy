#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <string>
#include <vector>

class SpriteSpawner
{
public:
	SpriteSpawner(const int& startYCoord, const bool startsOnLeft);
	~SpriteSpawner();

	sf::Sprite* SpriteHasBeenClicked(const sf::Vector2i& clickPosition, bool& anIsSalami);
	sf::Sprite* SpawnRandomSprite();
	void Update(sf::RenderWindow* aWindow, const bool aMove);
private:
	sf::Sprite* mySprite1;
	sf::Sprite* mySprite2;
	bool mySprite1IsSalami;
	bool mySprite2IsSalami;
	std::vector<sf::Texture*> myTextures;
	const bool myStartsOnLeft;
	const int myYCoord;
};


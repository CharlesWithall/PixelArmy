#include "SpriteSpawner.h"

#include "AssetPool.h"

#include <iostream>

SpriteSpawner::SpriteSpawner(const int& startYCoord, const bool startsOnLeft) : myYCoord(startYCoord), myStartsOnLeft(startsOnLeft)
{
	std::string filePath = std::string(RESOURCE_FOLDER) + std::string("PickSalami\\");
	std::vector<std::string> strings = { "NotSalami1.jpg","NotSalami2.jpg","NotSalami3.jpg","NotSalami4.jpg","NotSalami5.jpg","NotSalami6.jpg","Salami1.jpg","Salami2.jpg","Salami3.jpg" };

	for (std::string s : strings)
	{
		sf::Texture* texture = new sf::Texture();
		if (texture->loadFromFile(filePath + s))
		{
			myTextures.push_back(texture);
		}
	}	
}

SpriteSpawner::~SpriteSpawner()
{
	for (auto tex : myTextures)
	{
		delete tex;
	}
}

sf::Sprite* SpriteSpawner::SpawnRandomSprite()
{
	int XCoord = myStartsOnLeft ? -200 : 1000;
	int iRand = rand() % 9;

	sf::Sprite* sprite;

	if (!mySprite1)
	{
		mySprite1 = new sf::Sprite();
		sprite = mySprite1;
		mySprite1IsSalami = (iRand > 5);
	}
		
	else if (!mySprite2)
	{
		mySprite2 = new sf::Sprite();
		sprite = mySprite2;
		mySprite2IsSalami = (iRand > 5);
	}
		
	else { return nullptr; }
	
	sprite->setTexture(*myTextures[iRand]);
	std::cout << XCoord << myYCoord << std::endl;
	sprite->setPosition(XCoord, myYCoord);

	

	return sprite;
}

void SpriteSpawner::Update(sf::RenderWindow* aWindow, const bool aMove)
{
	float moveDistance = myStartsOnLeft ? 1.f : -1.f;
	
	if (mySprite1 && ((!myStartsOnLeft && mySprite1->getPosition().x < -200) || (myStartsOnLeft && mySprite1->getPosition().x > 1000)))
	{
		delete mySprite1;
		mySprite1 = nullptr;
	}

	if (mySprite2 && ((!myStartsOnLeft && mySprite2->getPosition().x < -200) || (myStartsOnLeft && mySprite2->getPosition().x > 1000)))
	{
		delete mySprite2;
		mySprite2 = nullptr;
	}

	if (mySprite1)
	{
		if (aMove)
			mySprite1->move(sf::Vector2f(moveDistance, 0));
		
		aWindow->draw(*mySprite1);
	}
		
	if (mySprite2)
	{
		if (aMove)
			mySprite2->move(sf::Vector2f(moveDistance, 0));
		
		aWindow->draw(*mySprite2);
	}		
}

sf::Sprite* SpriteSpawner::SpriteHasBeenClicked(const sf::Vector2i& clickPosition, bool& anIsSalami)
{
	if (mySprite1)
	{
		const sf::Vector2f spritePosition = mySprite1->getPosition();
		const int size = 200;
		const bool isBetweenXBounds = (spritePosition.x < clickPosition.x && spritePosition.x + size > clickPosition.x);
		const bool isBetweenYBounds = (spritePosition.y < clickPosition.y && spritePosition.y + size > clickPosition.y);

		if (isBetweenXBounds && isBetweenYBounds)
		{
			std::cout << "Click Success 1!" << std::endl;
			anIsSalami = mySprite1IsSalami;
			return mySprite1;
		}
	}

	if (mySprite2)
	{
		const sf::Vector2f spritePosition = mySprite2->getPosition();
		const int size = 200;
		const bool isBetweenXBounds = (spritePosition.x < clickPosition.x && spritePosition.x + size > clickPosition.x);
		const bool isBetweenYBounds = (spritePosition.y < clickPosition.y && spritePosition.y + size > clickPosition.y);

		if (isBetweenXBounds && isBetweenYBounds)
		{
			std::cout << "Click Success 2!" << std::endl;
			anIsSalami = mySprite2IsSalami;
			return mySprite2;
		}
			
	}

	return nullptr;
}
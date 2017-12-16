#include "GameEntity.h"
#include "Behaviour.h"
#include "EntityPool.h"

sf::Vector2f GameEntity::ourWindowScale;

GameEntity::GameEntity(const sf::Texture& aTexture, const sf::Vector2f& aPosition)
{
	Init(aTexture, aPosition);
}

GameEntity::GameEntity(const sf::Texture& aTexture, const sf::Vector2f& aPosition, const sf::Vector2f& aSize)
{
	Init(aTexture, aPosition, aSize);
}

void GameEntity::Init(const sf::Texture& aTexture, const sf::Vector2f& aPosition)
{
	mySprite = new sf::Sprite(aTexture);
	sf::Vector2f pos = sf::Vector2f(aPosition.x, aPosition.y);
	mySprite->setPosition(pos);
	mySprite->setScale(ourWindowScale);

	bool isBeingRecycled = false;
	for (auto entity : EntityPool::ourEntityPool)
	{
		if (entity == this)
		{
			isBeingRecycled = true;
			break;
		}
	}

	if (!isBeingRecycled)
		EntityPool::ourEntityPool.push_back(this);

	myIsActive = true;
}

void GameEntity::Init(const sf::Texture& aTexture, const sf::Vector2f& aPosition, const sf::Vector2f& aSize)
{
	Init(aTexture, aPosition);
	mySprite->setScale(sf::Vector2f(mySprite->getScale().x * aSize.x, mySprite->getScale().y * aSize.y));
}

GameEntity::~GameEntity()
{
	EntityPool::ourEntityPool.erase(std::remove(EntityPool::ourEntityPool.begin(), EntityPool::ourEntityPool.end(), this), EntityPool::ourEntityPool.end());
	delete mySprite;

	for (Behaviour* behaviour : myBehaviours)
	{
		delete behaviour;
	}
}

void GameEntity::UpdateBehaviour(Player_Shared* aPlayerSharedData, const float& aTimeElapsed)
{
	for (Behaviour* behaviour : myBehaviours)
	{
		if (behaviour->ShouldExecute(this, aPlayerSharedData))
		{
			behaviour->Execute(this, aPlayerSharedData, aTimeElapsed);
			return;
		}
	}
}

void GameEntity::Render(sf::RenderWindow* aWindow)
{
	if (myIsActive)
	{
		aWindow->draw(*mySprite);
	}	
}

bool GameEntity::WaitForSeconds(const float& aSecondsToWait, const float& aTimeElapsed)
{
	if (myTimeWaited < aSecondsToWait)
	{
		myTimeWaited += aTimeElapsed;
		return false;
	}
	
	myTimeWaited = 0;
	return true;
}
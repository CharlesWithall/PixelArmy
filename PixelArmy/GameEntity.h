#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Player_Shared.h"

class Behaviour;

class GameEntity
{
public:
	GameEntity(const sf::Texture& aTexture, const sf::Vector2f& aPosition);
	GameEntity(const sf::Texture& aTexture, const sf::Vector2f& aPosition, const sf::Vector2f& aSize);
	~GameEntity();

	void Init(const sf::Texture& aTexture, const sf::Vector2f& aPosition);
	void Init(const sf::Texture& aTexture, const sf::Vector2f& aPosition, const sf::Vector2f& aSize);

	void Move(const sf::Vector2f& aDirection) { mySprite->move(aDirection); }
	void Render(sf::RenderWindow* aWindow);
	virtual void Update(const float& aTimeElapsed) {}
	void UpdateBehaviour(Player_Shared* aPlayerSharedData, const float& aTimeElapsed);
	const bool GetIsActive() { return myIsActive; }
	const sf::Vector2f GetPosition() { return mySprite->getPosition(); }

	void SetIsActive(const bool anIsActive) { myIsActive = anIsActive; }
	static void SetRenderScale(const sf::Vector2f& aScalingVector) { ourWindowScale = aScalingVector; }
	bool WaitForSeconds(const float& aSecondsToWait, const float& aTimeElapsed);
protected:
	std::vector<Behaviour*> myBehaviours;
private:
	sf::Sprite* mySprite;
	bool myIsActive;
	float myTimeWaited;

	static sf::Vector2f ourWindowScale;
	
};


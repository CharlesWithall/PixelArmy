#pragma once
#include "Behaviour.h"

class MoveOnAxisBehaviour : public Behaviour
{
public:
	MoveOnAxisBehaviour(const sf::Vector2f& aMovementVector);
	~MoveOnAxisBehaviour();

	bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) override;
	void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) override;
private:
	sf::Vector2f myMovementVector;
};


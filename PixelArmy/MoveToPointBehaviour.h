#pragma once
#include "Behaviour.h"

class MoveToPointBehaviour : public Behaviour
{
public:
	MoveToPointBehaviour(const float aSpeed);
	~MoveToPointBehaviour();

	bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) override;
	void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) override;
private:
	float mySpeed;
};


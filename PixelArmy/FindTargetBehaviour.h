#pragma once
#include "Behaviour.h"

class FindTargetBehaviour : public Behaviour
{
public:
	FindTargetBehaviour();
	~FindTargetBehaviour();

	bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) override;
	void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) override;
private:
	const int myDistanceToTrigger = 50;
};


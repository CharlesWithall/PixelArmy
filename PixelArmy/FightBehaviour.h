#pragma once

#include "Behaviour.h"

class FightBehaviour : public Behaviour
{
public:
	FightBehaviour();
	~FightBehaviour();

	bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) override;
	void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) override;
};


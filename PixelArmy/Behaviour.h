#pragma once

#include "GameEntity.h"

class Behaviour
{
public:
	Behaviour();
	virtual ~Behaviour() = 0;

	virtual bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) = 0;
	virtual void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) = 0;
};


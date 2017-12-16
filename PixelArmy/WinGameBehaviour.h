#pragma once

#include "Behaviour.h"

class WinGameBehaviour : public Behaviour
{
public:
	WinGameBehaviour();
	~WinGameBehaviour();

	bool ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData) override;
	void Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed) override;
};


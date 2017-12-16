#pragma once

#include "IPlayerComponent.h"

class Player;

class EndgameComponent : public IPlayerComponent
{
public:
	EndgameComponent(Player* anAgent);
	~EndgameComponent();

	virtual void Update() override;
	void ProcessPlayerHasWonTheGame() {};
private:
	Player* myAgent;
};


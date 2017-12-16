#include "Soldier.h"
#include "WinGameBehaviour.h"

WinGameBehaviour::WinGameBehaviour()
{
}


WinGameBehaviour::~WinGameBehaviour()
{
}

bool WinGameBehaviour::ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		if (aPlayerSharedData->GetEnemyBacklineLocation(soldier->GetOwner()))
		{
			// Send an event you dumb dumb
			// Need to calculate if passed the backline
			// Need to set a backline on players
			// Need to set execute behaviour
			return true;
		}
	}

	return false;
}

void WinGameBehaviour::Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed)
{
	// WIN WIN WIN!!!
}

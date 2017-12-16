#include "FindTargetBehaviour.h"
#include "Soldier.h"

FindTargetBehaviour::FindTargetBehaviour()
{
}


FindTargetBehaviour::~FindTargetBehaviour()
{
}

bool FindTargetBehaviour::ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		if (!soldier->GetTarget() || !soldier->GetTarget()->GetIsActive())
		{
			if (Soldier* potentialTarget = aPlayerSharedData->GetClosestEnemySoldierTo(soldier->GetPosition(), soldier->GetOwner()))
			{
				if (abs(aGameEntity->GetPosition().x - potentialTarget->GetPosition().x) < myDistanceToTrigger)
				{
					return true;
				}
			}
		}
	}

	return false;
}

void FindTargetBehaviour::Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& /*aTimeElapsed*/)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		soldier->SetTarget(aPlayerSharedData->GetClosestEnemySoldierTo(soldier->GetPosition(), soldier->GetOwner()));
	}
}

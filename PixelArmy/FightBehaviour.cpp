#include "FightBehaviour.h"
#include "Soldier.h"

FightBehaviour::FightBehaviour()
{
}


FightBehaviour::~FightBehaviour()
{
}

bool FightBehaviour::ShouldExecute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		if (Soldier* targetSoldier = soldier->GetTarget())
		{
			if (targetSoldier->GetIsActive())
			{
				int xDist = abs(soldier->GetPosition().x - soldier->GetTarget()->GetPosition().x);
				int yDist = abs(soldier->GetPosition().y - soldier->GetTarget()->GetPosition().y);

				if (xDist < 2 && yDist < 2)
				{
					switch (soldier->GetOwner())
					{
					case PlayerID::PlayerOne:
						return aGameEntity->GetPosition().x >= aPlayerSharedData->GetFrontlineLocation();
					case PlayerID::PlayerTwo:
						return aGameEntity->GetPosition().x <= aPlayerSharedData->GetFrontlineLocation();
					}
				}
			}
		}
	}
	
	return false;
}

void FightBehaviour::Execute(GameEntity* aGameEntity, Player_Shared* aPlayerSharedData, const float& aTimeElapsed)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		if (soldier->WaitForSeconds(soldier->GetAttackSpeed(), aTimeElapsed))
		{
			soldier->AttackTarget();
		}
	}
}
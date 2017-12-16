#include "MoveToPointBehaviour.h"
#include "Soldier.h"

MoveToPointBehaviour::MoveToPointBehaviour(const float aSpeed) :
	mySpeed(aSpeed)
{
}


MoveToPointBehaviour::~MoveToPointBehaviour()
{
}

bool MoveToPointBehaviour::ShouldExecute(GameEntity* aGameEntity, Player_Shared* /*aPlayerSharedData*/)
{
	if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
	{
		return soldier->GetTarget() && soldier->GetTarget()->GetIsActive();
	}
		

	return false;
}

void MoveToPointBehaviour::Execute(GameEntity* aGameEntity, Player_Shared* /*aPlayerSharedData*/, const float& aTimeElapsed)
{
	if (aGameEntity->WaitForSeconds(0.05f, aTimeElapsed))
	{
		if (Soldier* soldier = static_cast<Soldier*>(aGameEntity))
		{
			if (Soldier* targetSoldier = soldier->GetTarget())
			{
				sf::Vector2f direction = targetSoldier->GetPosition() - soldier->GetPosition();
				float totalDist = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
				sf::Vector2f normalizedDirection = direction / totalDist;
				aGameEntity->Move(normalizedDirection * mySpeed);
			}
		}
	}
}

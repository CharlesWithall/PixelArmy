#include "MoveOnAxisBehaviour.h"



MoveOnAxisBehaviour::MoveOnAxisBehaviour(const sf::Vector2f& aMovementVector) : myMovementVector(aMovementVector)
{
}


MoveOnAxisBehaviour::~MoveOnAxisBehaviour()
{
}

bool MoveOnAxisBehaviour::ShouldExecute(GameEntity* /*aGameEntity*/, Player_Shared* /*aPlayerSharedData*/)
{
	return true;
}

void MoveOnAxisBehaviour::Execute(GameEntity* aGameEntity, Player_Shared* /*aPlayerSharedData*/, const float& aTimeElapsed)
{
	if (aGameEntity->WaitForSeconds(0.05f, aTimeElapsed))
	{
		aGameEntity->Move(myMovementVector);
	}
}

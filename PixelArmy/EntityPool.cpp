#include "EntityPool.h"
#include "GameEntity.h"

std::vector<GameEntity*> EntityPool::ourEntityPool;


void EntityPool::RenderAll(sf::RenderWindow* aWindow)
{
	for (GameEntity* entity : ourEntityPool)
	{
		entity->Render(aWindow);
	}
}

void EntityPool::UpdateAll(Player_Shared* aPlayerSharedData, const float& aTimeElapsed)
{
	int poolSize = ourEntityPool.size();

	for (int i = 0; i < poolSize; ++i)
	{
		ourEntityPool[i]->Update(aTimeElapsed);
		ourEntityPool[i]->UpdateBehaviour(aPlayerSharedData, aTimeElapsed);
	}
}

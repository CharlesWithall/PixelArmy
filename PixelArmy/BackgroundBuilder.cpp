#include "AssetPool.h"
#include "BackgroundBuilder.h"
#include "GameEntity.h"

BackgroundBuilder::BackgroundBuilder()
{

}


BackgroundBuilder::~BackgroundBuilder()
{
}

void BackgroundBuilder::CreateBackground(sf::Texture* aTexture)
{
	GameEntity* backgroundEntity = new GameEntity(*aTexture, sf::Vector2f(0, 0));
}

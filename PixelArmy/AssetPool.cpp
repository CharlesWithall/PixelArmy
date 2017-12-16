#include "AssetPool.h"
#include "DEBUG.h"


AssetPool::AssetPool()
{
	InitTexture(FILEPATH_BACKGROUND_TEXTURE, &myBackgroundTexture);
	InitTexture(FILEPATH_BUILDING_TEXTURE, &myBuildingTexture);
	InitTexture(FILEPATH_MELEESOLDIER_TEXTURE, &myMeleeSoldierTexture);
}

AssetPool::~AssetPool()
{
	delete myBackgroundTexture;
	delete myBuildingTexture;
	delete myMeleeSoldierTexture;
}

void AssetPool::InitTexture(const std::string& aFilePath, sf::Texture** aTexture)
{
	*aTexture = new sf::Texture();
	if (!(*aTexture)->loadFromFile(RESOURCE_FOLDER + aFilePath))
		DEBUG::Log("Error loading " + aFilePath);
}

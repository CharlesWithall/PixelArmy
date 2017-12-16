#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#define RESOURCE_FOLDER "C:\\Users\\Cyrus\\Documents\\Visual Studio 2015\\Projects\\PixelArmy\\Resources\\"
#define FILEPATH_BUILDING_TEXTURE "Building_Placeholder.png"
#define FILEPATH_MELEESOLDIER_TEXTURE "MeleeSoldier_Placeholder.png"
#define FILEPATH_BACKGROUND_TEXTURE "Background_Full_Placeholder.png"

class AssetPool
{
public:
	AssetPool();
	~AssetPool();

	sf::Texture* const GetBackgroundTexture() { return myBackgroundTexture; }
	sf::Texture* const GetBuildingTexture() { return myBuildingTexture; }
	sf::Texture* const GetMeleeSoldierTexture() { return myMeleeSoldierTexture; }
private:
	sf::Texture* myBackgroundTexture;
	sf::Texture* myBuildingTexture;
	sf::Texture* myMeleeSoldierTexture;

	void InitTexture(const std::string& aFilePath, sf::Texture** aTexture);
};


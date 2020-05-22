#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "AssetPool.h"
#include "BackgroundBuilder.h"
#include "Command.h"
#include "EntityPool.h"
#include "GameEntity.h"
#include "InputHandler.h"
#include "Player.h"
#include "Player_Shared.h"
#include "World.h"

class PixelArmy
{
public:
	PixelArmy() {}
	~PixelArmy() {}

	void Run();
private:
	void Init();
	void CleanUp();
	void Render();
	void Update();

	sf::RenderWindow* myWindow;
	Player* myPlayerOne;
	Player* myPlayerTwo;
	Player_Shared* myPlayerSharedData;
	InputHandler* myInputHandler;

	sf::Event myEvent;
	sf::Clock myClock;
	float myTimeElapsed;

	const static int ourDefaultScreenSizeX = 1440;
	const static int ourDefaultScreenSizeY = 810;
	const static int ourNativeResolutionX = 1920;
	const static int ourNativeResolutionY = 1080;
	const std::string myGameTitle = "Pixel Army";
};
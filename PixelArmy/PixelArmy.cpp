#include "PixelArmy.h"

void PixelArmy::Run()
{
	Init();

	while (myWindow->isOpen())
	{
		myTimeElapsed = myClock.restart().asMicroseconds() * 0.000001;

		while (myWindow->pollEvent(myEvent))
		{
			if (Command* command = myInputHandler->HandleInput(myPlayerOne, myEvent))
			{
				command->Execute(myPlayerOne);
				delete command;
			}
			else if (Command* command = myInputHandler->HandleInput(myPlayerTwo, myEvent))
			{
				command->Execute(myPlayerTwo);
				delete command;
			}

			if (myEvent.type == sf::Event::Closed)
				myWindow->close();
		}

		Update();
		Render();
	}

	CleanUp();
}

void PixelArmy::Init()
{
	sf::Vector2f scalingVector = sf::Vector2f(static_cast<float>(ourDefaultScreenSizeX) / static_cast<float>(ourNativeResolutionX),
		static_cast<float>(ourDefaultScreenSizeY) / static_cast<float>(ourNativeResolutionY));

	myWindow = new sf::RenderWindow(sf::VideoMode(ourDefaultScreenSizeX, ourDefaultScreenSizeY), myGameTitle);
	GameEntity::SetRenderScale(scalingVector);
	myPlayerOne = new Player(PlayerID::PlayerOne, scalingVector);
	myPlayerTwo = new Player(PlayerID::PlayerTwo, scalingVector);
	myPlayerSharedData = new Player_Shared(myPlayerOne, myPlayerTwo);
	myInputHandler = new InputHandler();
}

void PixelArmy::CleanUp()
{
	delete myInputHandler;
	delete myPlayerSharedData;
	delete myPlayerTwo;
	delete myPlayerOne;
	delete myWindow;
}

void PixelArmy::Render()
{
	myWindow->clear();

	EntityPool::RenderAll(myWindow);

	myWindow->display();
}

void PixelArmy::Update()
{
	EntityPool::UpdateAll(myPlayerSharedData, myTimeElapsed);
}

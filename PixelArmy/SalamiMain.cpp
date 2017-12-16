#include "SalamiMain.h"
#include "SpriteSpawner.h"
#include "TextWriter.h"
#include "ThemeTune.h"
#include <SFML/Graphics.hpp>

SalamiMain::SalamiMain()
{
}


SalamiMain::~SalamiMain()
{
}

void SalamiMain::Run()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Pick Salami");
	SpriteSpawner* spawner1 = new SpriteSpawner(spawnerY1, true);
	SpriteSpawner* spawner2 = new SpriteSpawner(spawnerY2, false);
	SpriteSpawner* spawner3 = new SpriteSpawner(spawnerY3, true);
	TextWriter* textWriter = new TextWriter();
	ThemeTune* themeTune = new ThemeTune();
	bool successfulClick = false;
	bool showMessage = false;

	sf::Clock clock;
	sf::Time timeAccumulated;
	sf::Time messageTimeAccumulated;

	themeTune->PlayThemeTune();

	while (window.isOpen())
	{	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				bool isSalami = false;

				if (sf::Sprite* clickedSprite = spawner1->SpriteHasBeenClicked(sf::Mouse::getPosition(window), isSalami))
				{
					successfulClick = isSalami;
					messageTimeAccumulated = sf::Time::Zero;
					showMessage = true;
				}

				if (sf::Sprite* clickedSprite = spawner2->SpriteHasBeenClicked(sf::Mouse::getPosition(window), isSalami))
				{
					successfulClick = isSalami;
					messageTimeAccumulated = sf::Time::Zero;
					showMessage = true;
				}

				if (sf::Sprite* clickedSprite = spawner3->SpriteHasBeenClicked(sf::Mouse::getPosition(window), isSalami))
				{
					successfulClick = isSalami;
					messageTimeAccumulated = sf::Time::Zero;
					showMessage = true;
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		if (timeAccumulated.asSeconds() > myTimeBeforeSpawn)
		{
			spawner1->SpawnRandomSprite();
			spawner2->SpawnRandomSprite();
			spawner3->SpawnRandomSprite();
			timeAccumulated = sf::Time::Zero;
		}
		
		bool move = false;

		if (mySpeedTimeAccumulated.asMicroseconds() > mySpeed)
		{
			move = true;
			mySpeedTimeAccumulated = sf::Time::Zero;
		}

		spawner1->Update(&window, move);
		spawner2->Update(&window, move);
		spawner3->Update(&window, move);

		if (showMessage)
		{
			textWriter->WriteMessage(&window, successfulClick);
		}
		

		window.display();

		sf::Time elapsed = clock.restart();
		timeAccumulated += elapsed;
		mySpeedTimeAccumulated += elapsed;

		if (showMessage)
		{
			messageTimeAccumulated += elapsed;

			if (messageTimeAccumulated.asSeconds() > 1)
			{
				showMessage = false;
				messageTimeAccumulated = sf::Time::Zero;
			}
		}

		
	}

	delete spawner1;
	delete spawner2;
	delete spawner3;
	delete textWriter;
	delete themeTune;
}

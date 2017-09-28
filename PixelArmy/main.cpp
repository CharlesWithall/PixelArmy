#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Command.h"
#include "Player.h"
#include "SalamiMain.h"

int main()
{
	bool ENABLE_SALAMI = true;

	if (ENABLE_SALAMI)
	{
		SalamiMain* salamiMain = new SalamiMain();
		salamiMain->Run();
	}
	else
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Pixel Army");

		Player* playerOne = new Player();
		Player* playerTwo = new Player();
		InputHandler* inputHandler = new InputHandler();

		while (window.isOpen())
		{
			window.clear();
			sf::Event event;
			while (window.pollEvent(event))
			{
				Command* command = inputHandler->HandleInput(playerOne, event);
				if (!command) command = inputHandler->HandleInput(playerTwo, event);

				if (command)
				{
					//command->Execute();
					delete command;
				}

				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.display();
		}

		delete inputHandler;
	}

	return 0;
}
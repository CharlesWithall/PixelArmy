#include "InputHandler.h"

InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

Command* InputHandler::HandleInput(Player* const aPlayer, const sf::Event& anEvent)
{
	if (anEvent.type == sf::Event::KeyPressed)
	{
		switch (aPlayer->GetPlayerID())
		{
		case PlayerID::PlayerOne:
			return HandlePlayerOne(anEvent);
			break;
		case PlayerID::PlayerTwo:
			return HandlePlayerTwo(anEvent);
			break;
		}
	}

	return nullptr;
}

Command* InputHandler::HandlePlayerOne(const sf::Event& anEvent)
{
	if (anEvent.key.code == sf::Keyboard::Z)
	{
		return new BuildCommand();
	}
	if (anEvent.key.code == sf::Keyboard::X)
	{
		// return new UpgradeCommand();
	}
	if (anEvent.key.code == sf::Keyboard::C)
	{
		// return new CollaborateCommand();
	}

	return nullptr;
}

Command* InputHandler::HandlePlayerTwo(const sf::Event& anEvent)
{
	if (anEvent.key.code == sf::Keyboard::Numpad1)
	{
		return new BuildCommand();
	}
	if (anEvent.key.code == sf::Keyboard::Numpad2)
	{
		// return new UpgradeCommand();
	}
	if (anEvent.key.code == sf::Keyboard::Numpad3)
	{
		// return new CollaborateCommand();
	}

	return nullptr;
}

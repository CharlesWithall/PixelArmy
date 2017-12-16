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
	CityRegion selectedRegion = CityRegion::INVALID;

	switch (anEvent.key.code)
	{
	case sf::Keyboard::Q:
		selectedRegion = CityRegion::NORTHWEST;
		break;
	case sf::Keyboard::W:
		selectedRegion = CityRegion::NORTH;
		break;
	case sf::Keyboard::E:
		selectedRegion = CityRegion::NORTHEAST;
		break;
	case sf::Keyboard::A:
		selectedRegion = CityRegion::WEST;
		break;
	case sf::Keyboard::S:
		selectedRegion = CityRegion::CENTRAL;
		break;
	case sf::Keyboard::D:
		selectedRegion = CityRegion::EAST;
		break;
	case sf::Keyboard::Z:
		selectedRegion = CityRegion::SOUTHWEST;
		break;
	case sf::Keyboard::X:
		selectedRegion = CityRegion::SOUTH;
		break;
	case sf::Keyboard::C:
		selectedRegion = CityRegion::SOUTHEAST;
		break;
	}

	if (selectedRegion != CityRegion::INVALID)
		return new BuildCommand(selectedRegion);
	else
		return nullptr;
}

Command* InputHandler::HandlePlayerTwo(const sf::Event& anEvent)
{
	CityRegion selectedRegion = CityRegion::INVALID;

	switch (anEvent.key.code)
	{
	case sf::Keyboard::Numpad7:
		selectedRegion = CityRegion::NORTHWEST;
		break;
	case sf::Keyboard::Numpad8:
		selectedRegion = CityRegion::NORTH;
		break;
	case sf::Keyboard::Numpad9:
		selectedRegion = CityRegion::NORTHEAST;
		break;
	case sf::Keyboard::Numpad4:
		selectedRegion = CityRegion::WEST;
		break;
	case sf::Keyboard::Numpad5:
		selectedRegion = CityRegion::CENTRAL;
		break;
	case sf::Keyboard::Numpad6:
		selectedRegion = CityRegion::EAST;
		break;
	case sf::Keyboard::Numpad1:
		selectedRegion = CityRegion::SOUTHWEST;
		break;
	case sf::Keyboard::Numpad2:
		selectedRegion = CityRegion::SOUTH;
		break;
	case sf::Keyboard::Numpad3:
		selectedRegion = CityRegion::SOUTHEAST;
		break;
	}

	if (selectedRegion != CityRegion::INVALID)
		return new BuildCommand(selectedRegion);
	else
		return nullptr;
}

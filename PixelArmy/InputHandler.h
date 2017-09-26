#pragma once

#include "BuildCommand.h"
#include "Command.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* HandleInput(Player* const aPlayer, const sf::Event& anEvent);
private:
	Command* HandlePlayerOne(const sf::Event& anEvent);
	Command* HandlePlayerTwo(const sf::Event& anEvent);
};


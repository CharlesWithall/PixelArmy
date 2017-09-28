#pragma once
#include <SFML/Graphics.hpp>

class TextWriter
{
public:
	TextWriter();
	~TextWriter();

	void WriteMessage(sf::RenderWindow* aWindow, const bool isSuccessfulPick);
private:
	sf::Font myFont;
};


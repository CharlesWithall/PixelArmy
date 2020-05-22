#include "TextWriter.h"

#include "AssetPool.h"

TextWriter::TextWriter()
{
	myFont.loadFromFile(std::string(RESOURCE_FOLDER) + std::string("PickSalami\\JOKERMAN.TTF"));
}


TextWriter::~TextWriter()
{
}

void TextWriter::WriteMessage(sf::RenderWindow* aWindow, const bool isSuccessfulPick)
{
	sf::Text text;
	sf::Color textColour = isSuccessfulPick ? sf::Color::Green : sf::Color::Red;
	std::string message = isSuccessfulPick ? "!!! SALAMI !!!" : "!!! NOT SALAMI !!!";
	int textSize = isSuccessfulPick ? 100 : 70;
	
	text.setFont(myFont);
	text.setString(message);
	text.setCharacterSize(textSize);
	text.setFillColor(textColour);
	text.setStyle(sf::Text::Bold);
	text.setPosition(sf::Vector2f(40, 40));

	aWindow->draw(text);
}

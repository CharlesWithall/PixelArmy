#pragma once
#include <SFML/Graphics.hpp>
#include "DEBUG.h"

class BackgroundBuilder
{
public:
	BackgroundBuilder();
	~BackgroundBuilder();

	void CreateBackground(sf::Texture* aTexture);
};


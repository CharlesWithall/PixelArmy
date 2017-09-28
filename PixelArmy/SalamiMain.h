#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SalamiMain
{
public:
	SalamiMain();
	~SalamiMain();
	void Run();
	
private:
	const int spawnerY1 = 200;
	const int spawnerY2 = 400;
	const int spawnerY3 = 600;
	const float myTimeBeforeSpawn = 1.5f;
	const int mySpeed = 1;
	sf::Time mySpeedTimeAccumulated;
};


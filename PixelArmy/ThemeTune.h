#pragma once
#include <SFML/Audio.hpp>

class ThemeTune
{
public:
	ThemeTune();
	~ThemeTune();

	void PlayThemeTune();
private:
	sf::SoundBuffer myAudioFile;
	sf::Sound* myAudioPlayer;
};


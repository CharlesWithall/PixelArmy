#include "ThemeTune.h"

ThemeTune::ThemeTune()
{
	myAudioFile.loadFromFile("C:\\Users\\Cyrus\\Documents\\Visual Studio 2015\\Projects\\PixelArmy\\Resources\\PickSalami\\ThemeTune-001.wav");
	myAudioPlayer = new sf::Sound();
}


ThemeTune::~ThemeTune()
{
	delete myAudioPlayer;
}

void ThemeTune::PlayThemeTune()
{
	myAudioPlayer->setBuffer(myAudioFile);
	myAudioPlayer->setLoop(true);
	myAudioPlayer->play();
}

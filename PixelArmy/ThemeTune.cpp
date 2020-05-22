#include "ThemeTune.h"

#include "AssetPool.h"

ThemeTune::ThemeTune()
{
	myAudioFile.loadFromFile(std::string(RESOURCE_FOLDER) + std::string("PickSalami\\ThemeTune-001.wav"));
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

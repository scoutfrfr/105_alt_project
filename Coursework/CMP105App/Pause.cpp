#include "Pause.h"

Pause::Pause(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	Scene(hwnd, in, gs, aud)
{

}

void Pause::handleInput(float dt)
{

}

void Pause::update(float dt)
{

}

void Pause::render()
{
	beginDraw();
	endDraw();
}

void Pause::onBegin()
{
	std::cout << "Pause scene is active\n";
}

void Pause::onEnd()
{
	std::cout << "Pause scene is finished\n";

}


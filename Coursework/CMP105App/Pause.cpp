#include "Pause.h"

Pause::Pause(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	Scene(hwnd, in, gs, aud), m_pauseText(m_font)
{
	if (!m_font.openFromFile("font/bitcount.ttf"))
		std::cerr << "failed to load bitcount font";

	m_pauseText.setCharacterSize(24);		// setup labels
	m_pauseText.setPosition({ 120,163 });
	m_pauseText.setString("Press escape to return");
	m_pauseText.setFillColor(sf::Color::Black);
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
	m_window.draw(m_pauseText);
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


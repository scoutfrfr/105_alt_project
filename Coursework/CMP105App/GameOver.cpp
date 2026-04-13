#include "GameOver.h"


GameOver::GameOver(sf::RenderWindow& hwnd, Input& in, GameState& gs, AudioManager& aud) :
	Scene(hwnd, in, gs, aud), m_menuButtonLabel(m_font)
{
	if (!m_font.openFromFile("font/bitcount.ttf"))
		std::cerr << "failed to load bitcount font";

	m_menuButtonLabel.setCharacterSize(24);		// setup labels
	m_menuButtonLabel.setPosition({ 120,163 });
	m_menuButtonLabel.setString("Return to Menu");
	m_menuButtonLabel.setFillColor(sf::Color::Black);

	m_menuButton.setSize({ 216,100 });			// setup buttons
	m_menuButton.setPosition({ 108,128 });
	m_menuButton.setCollisionBox({ {0,0}, m_menuButton.getSize() });
	m_menuButton.setFillColor(m_defaultButtonColour);
}

void GameOver::handleInput(float dt)
{
	sf::Vector2i mousePos{ m_input.getMouseX(), m_input.getMouseY() };
	if (m_input.isLeftMousePressed() &&
		Collision::checkBoundingBox(m_menuButton, mousePos))
	{
		m_gameState.setCurrentState(State::MENU);
	}
}

void GameOver::update(float dt)
{
	sf::Vector2i mousePos{ m_input.getMouseX(), m_input.getMouseY() };
	if (Collision::checkBoundingBox(m_menuButton, mousePos))
	{
		m_menuButton.setFillColor(m_hoverButtonColour);
	}
	else
	{
		m_menuButton.setFillColor(m_defaultButtonColour);
	}
}

void GameOver::render()
{
	beginDraw();
	m_window.draw(m_menuButton);
	m_window.draw(m_menuButtonLabel);
	endDraw();
}

void GameOver::onBegin()
{
	std::cout << "Game Over scene is active\n";
}

void GameOver::onEnd()
{
	std::cout << "Game Over scene is finished\n";
	
}

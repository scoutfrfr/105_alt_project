#include "Victory.h"

Victory::Victory(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio)
	: Scene(window, input, gameState, audio), m_backToMenuLabel(m_font), m_winText(m_font)
{
	if (!m_font.openFromFile("font/bitcount.ttf"))
		std::cerr << "failed to load bitcount font";

	m_backToMenuLabel.setCharacterSize(24);		// setup labels
	m_backToMenuLabel.setPosition({ 150,93 });
	m_backToMenuLabel.setString("Return to\nMenu");
	m_backToMenuLabel.setFillColor(sf::Color::Black);

	m_winText.setCharacterSize(36);
	m_winText.setPosition({ 120, 250 });
	m_winText.setString("You Won!");
	m_winText.setFillColor(sf::Color::Black);



	m_backToMenuButton.setSize({ 216,100 });			// setup buttons
	m_backToMenuButton.setPosition({ 108,58 });
	m_backToMenuButton.setCollisionBox({ {0,0}, m_backToMenuButton.getSize() });
	m_backToMenuButton.setFillColor(m_defaultButtonColour);
}

void Victory::handleInput(float dt)
{
	sf::Vector2i mousePos{ m_input.getMouseX(), m_input.getMouseY() };
	if (m_input.isLeftMousePressed() &&
		Collision::checkBoundingBox(m_backToMenuButton, mousePos))
	{
		m_gameState.setCurrentState(State::MENU);
	}
}

void Victory::update(float dt)
{
	sf::Vector2i mousePos{ m_input.getMouseX(), m_input.getMouseY() };
	if (Collision::checkBoundingBox(m_backToMenuButton, mousePos))
	{
		m_backToMenuButton.setFillColor(m_hoverButtonColour);
	}
	else
	{
		m_backToMenuButton.setFillColor(m_defaultButtonColour);
	}
}

void Victory::render()
{
	beginDraw();
	m_window.draw(m_backToMenuButton);
	m_window.draw(m_backToMenuLabel);
	m_window.draw(m_winText);
	endDraw();
}

void Victory::onBegin()
{
	std::cout << "starting victory screen\n";
	auto view = m_window.getDefaultView();
	view.setCenter({ 216, 216 });
	m_window.setView(view);
	m_audio.playMusicbyName("bgm2");
}

void Victory::onEnd()
{
	std::cout << "leaving victory screen\n";
	m_audio.stopAllMusic();
}

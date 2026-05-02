#include "UserInterface.h"

UserInterface::UserInterface() : m_healthDisplay(m_font)
{
	// Setup Text
	if (!m_font.openFromFile("font/bitcount.ttf")) std::cerr << "no font found";
	m_healthDisplay.setPosition({ 5, 0 });
	m_healthDisplay.setCharacterSize(25);
	m_healthDisplay.setFillColor(sf::Color::Black);

	
}

UserInterface::~UserInterface()
{
}


void UserInterface::drawUI(sf::RenderWindow& window, Player& player)
{
	// step one: get the references
	sf::View world_view = window.getView();
	sf::Vector2f middle = world_view.getCenter();
	sf::Vector2f vSize = world_view.getSize();

	// step two: set to default view
	window.setView(window.getDefaultView());

	m_health = player.getCurrentHealth();
	m_healthDisplay.setString("Health: " + std::to_string(static_cast<int>(m_health)));

	window.draw(m_healthDisplay);

	window.setView(world_view);
}




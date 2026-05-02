#pragma once
#include "Player.h"

class UserInterface
{
	public:
		UserInterface();
		~UserInterface();
		void drawUI(sf::RenderWindow& window, Player& player);

	private:
		sf::Text m_healthDisplay;
		sf::Font m_font;
		float m_health;

};


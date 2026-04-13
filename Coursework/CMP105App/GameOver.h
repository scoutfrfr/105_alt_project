#pragma once
#include "Scene.h"
#include "Framework/Collision.h"
class GameOver :
    public Scene
{
public:
    GameOver(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() override;
    void onBegin() override;
    void onEnd() override;
    

private:

    GameObject m_menuButton;

    sf::Font m_font;
    sf::Text m_menuButtonLabel;

    sf::Color m_defaultButtonColour = sf::Color(100, 250, 100, 50);
    sf::Color m_hoverButtonColour = sf::Color(80, 230, 80, 150);
};



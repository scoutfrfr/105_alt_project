#pragma once
#include "Scene.h"
#include "Framework/Collision.h"
#include "Framework/TileMap.h"
#include "Player.h"
#include "Coin.h"
#include "Lever.h"
#include "Enemy.h"
#include "Flag.h"
#include <algorithm> // for clamp
#include "UserInterface.h"

class LevelFourWithTiles :
    public Scene
{
public:
    LevelFourWithTiles(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() override;
    void onBegin() override;
    void onEnd() override;

private:
    void updateCameraAndBackground();
    void checkAndSetMessages();
    TileMap m_tilemap;
    TileMap m_bgtilemap;
    Player m_player;
    Flag m_flag;
    std::vector<Enemy*> m_enemyPointers;
    UserInterface m_ui;
    sf::Texture m_tileTexture;
    sf::Text m_alertText;
    sf::Font m_font;
    bool m_flagLeverPulled = false;
    bool m_gamePaused = false;
    bool m_enemyDead = false;

    float m_promptTimer;


    const float PROMPT_TIME = 2.f;
    const sf::Vector2i WORLD_SIZE = { 2880, 648 };
    const sf::Vector2i VIEW_SIZE = { 432, 432 };

};
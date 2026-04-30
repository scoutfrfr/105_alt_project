#pragma once
#include "Scene.h"
#include "Framework/Collision.h"

class Pause :
    public Scene
{
public:
    Pause(sf::RenderWindow& window, Input& input, GameState& gameState, AudioManager& audio);

    void handleInput(float dt) override;
    void update(float dt) override;
    void render() override;
    void onBegin() override;
    void onEnd() override;


private:

   
};



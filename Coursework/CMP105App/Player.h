#pragma once
#include "Scene.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <iostream>
#include "Framework/AudioManager.h"


class Player :
    public GameObject
{
public:
    Player();

    void handleInput(float dt) override;
    void update(float dt) override;
    void collisionResponse(GameObject& collider) override;
    void setEdges(float left, float right) { m_leftEdge = left; m_rightEdge = right; };
    void setLeverPosition(sf::Vector2f leverPos) { m_leverPosition = leverPos; };
    void setEndGamePosition(sf::Vector2f endPos) { m_endPosition = endPos; };
    bool inLeverRange();
    bool inEndRange();
    bool getLeverPulled() { return m_leverPulled; };
    bool getGameEndTriggered() { return m_gameEndTriggered; };
    void reset();
    void setCanDoubleJump(bool value) { m_canDoubleJump = value; };
    bool canDoubleJump() { return m_canDoubleJump; };
    void setAudio(AudioManager* audio) { m_audio = audio; };
    void takeDamage();
    void setCurrentHealth(float hp) { m_playerHealth = hp; };
    float getCurrentHealth() { return m_playerHealth; };
    bool playerAttack() { return m_isAttacking; };
    bool playerDeath();

private:
    sf::Texture m_dinoTexture;
    Animation* m_currAnim;
    Animation m_idle;
    Animation m_walk;
    Animation m_sprint;
    Animation m_attack;
    sf::Vector2f m_accel;
    float m_sprintTimer = 0.f;
    bool m_isGrounded;
    float m_leftEdge;
    float m_rightEdge;
    float m_playerHealth = 3.0f;
    float m_invincibilityDuration = 1.5f;
    float m_attackDuration = 1.f;
    sf::Vector2f m_leverPosition;
    sf::Vector2f m_endPosition;
    sf::Clock invincibilityClock;
    sf::Clock attackClock;
    bool m_leverPulled = false;
    bool m_gameEndTriggered = false;
    bool m_canDoubleJump;
    bool m_hasDoubleJumped;
    bool m_playerDead = false;
    bool m_isInvincible = false;
    bool m_isAttacking = false;
    bool m_weaponUnlocked = true;
    AudioManager* m_audio;

    const float SPRINT_COOLDOWN = 2.0f;
    const float SPRINT_SPEED_MULT = 2.5f;
    const float SPEED = 10.0f;
    const float GRAVITY = 50.0f;
    const float COEFF_OF_REST = 0.8f;
    const float DRAG_FACTOR = 0.9f;
    const float AIR_DRAG_FACTOR = 0.99f;
    const float TURN_DRAG = 0.6f;       // allow snappy decel for turning
    const float JUMP_FORCE = 20.0f;
    const float SPRINT_ANIM_THRESHOLD = 1.2f * SPEED;
    const float ACTIVATE_RANGE_SQUARED = 700.0f;

    

};


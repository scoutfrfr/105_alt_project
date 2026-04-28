#pragma once
#include "Scene.h"
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <iostream>
#include "Framework/AudioManager.h"

class Enemy :
	public GameObject
{
	public:

		Enemy();
		~Enemy();

		void update(float dt) override;
		void collisionResponse(GameObject& collider) override;
		void setEdges(float left, float right) { m_leftEdge = left; m_rightEdge = right; };
		void reset();

	private:
		sf::Texture m_enemyTexture;
		Animation* m_currAnim;
		Animation m_idle;
		Animation m_walk;
		Animation m_sprint;

		float m_leftEdge;
		float m_rightEdge;

		const float SPEED = 9.0f;
		const float SPRINT_ANIM_THRESHOLD = 1.2f * SPEED;
};


#include "Enemy.h"
#include "Framework/BaseLevel.h"

Enemy::Enemy()
{

	if (!m_enemyTexture.loadFromFile("gfx/enemy1.png"))
		std::cerr << "No enemy texture";

	setTexture(&m_enemyTexture);
	setSize({ 72,72 });

	for (int i = 0; i < 4; i++)
		m_idle.addFrame({ { i * 24, 0 }, { 24, 24} });
	for (int i = 4; i < 10; ++i)
		m_walk.addFrame({ { i * 24, 0 }, { 24, 24} });
	for (int i = 16; i < 24; i++)
		m_sprint.addFrame({ { i * 24, 0 }, { 24, 24} });

	m_currAnim = &m_walk;
	m_walk.setFrameSpeed(1.f / 10.f);
	m_idle.setFrameSpeed(1.f / 4.f);
	m_sprint.setFrameSpeed(1.4 / 15.0f);

	setCollisionBox({ {12,12}, { 45,51 } });

}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{

	// newtonian model
	m_velocity += dt * m_accel;
	if (m_isGrounded && abs(m_accel.x) < 1.f) m_velocity *= DRAG_FACTOR;
	else if (m_accel.x * m_velocity.x < 0) m_velocity *= TURN_DRAG;

	m_isGrounded = false;	// every frame we are falling unless proved otherwise by floor collision

	// handle animation
	float speed = std::abs(m_velocity.x);	// sideways speed
	if (speed < 1.0)
		m_currAnim = &m_idle;
	else if (speed > SPRINT_ANIM_THRESHOLD)
		m_currAnim = &m_sprint;
	else
		m_currAnim = &m_walk;

	// face direction
	if (m_velocity.x > 0 && m_currAnim->getFlipped()
		|| m_velocity.x < 0 && !m_currAnim->getFlipped())
		// if we gotta flip, flip.
		m_currAnim->setFlipped(!m_currAnim->getFlipped());

	move(m_velocity);

	// keep within L/R bounds
	if (getPosition().x < m_leftEdge)
	{
		setPosition({ m_leftEdge, getPosition().y });
	}
	if (getPosition().x > m_rightEdge - getSize().x)
	{
		setPosition({ m_rightEdge - getSize().x, getPosition().y });
	}

	m_currAnim->animate(dt);
	setTextureRect(m_currAnim->getCurrentFrame());

}

void Enemy::collisionResponse(GameObject& collider)
{
	std::cerr << "\n enemy collision";

	sf::FloatRect enemyCollider = getCollisionBox();
	sf::FloatRect wallBounds = collider.getCollisionBox();
	auto overlap = enemyCollider.findIntersection(wallBounds);
	if (!overlap) return; // if there is no overlap, then leave.
	if (overlap->size.x < overlap->size.y)
	{
		// taller than wide -> collision is side-on
		if (enemyCollider.position.x < wallBounds.position.x)
			move({ -overlap->size.x, 0 });
		else
			move({ overlap->size.x, 0 });
	}
	else
	{
		if (enemyCollider.position.y < wallBounds.position.y)
		{
			// We are above the wall (Landing)
			move({ 0, -overlap->size.y });
			m_velocity.y = 0;       // Stop falling
			m_isGrounded = true;    // Enable jumping
		}
		else
		{
			// We hit the ceiling (Bonk)
			move({ 0, overlap->size.y });
			m_velocity.y = 0;       // Stop moving up
		}
	}
}

void Enemy::reset()
{
	m_velocity = { 0,0 };
}

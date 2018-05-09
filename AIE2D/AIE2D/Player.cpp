#include "Player.h"
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>
const double PI = 3.1415926535897932384626433832795;

Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	m_angle = (0) * PI /180;
}


Player::~Player()
{
	delete m_texture;
}

void Player::Update(float deltaTime, aie::Input* input)
{
	float s = sin(m_angle);
	float c = cos(m_angle);
	float xNew = m_pos->x * c - m_pos->y * s;
	float yNew = m_pos->x * s + m_pos->y * c;
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		RotateLeft(60 * deltaTime);
		//m_pos->x -= 60.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		RotateRight(60 * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		if (speed < 250) {
			speed += 30;
			m_texture = new aie::Texture("../bin/textures/ship_moving.png");
		}
		//m_pos->y = yNew * deltaTime;
		//m_pos->y += 60.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		if (speed > 0)
			speed -= 30;
		if (speed == 0)
			m_texture = new aie::Texture("../bin/textures/ship.png");
	}
	if (m_pos->x > 1280)
		m_pos->x = 0;
	if (m_pos->x < 0)
		m_pos->x = 1280;
	if (m_pos->y > 720)
		m_pos->y = 0;
	if (m_pos->y < 0)
		m_pos->y = 720;
	if (speed > 0) {
		m_pos->x -= speed * (float)sin((m_angle)) * deltaTime;
		m_pos->y += speed * (float)cos((m_angle)) * deltaTime;
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y, 0, 0, m_angle);
}

void Player::RotateLeft(float input)
{
	m_angle = m_angle + (input)* PI / 180;
}

void Player::RotateRight(float input)
{
	m_angle = m_angle - (input)* PI / 180;
}
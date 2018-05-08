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
		RotateLeft(30 * deltaTime);
		//m_pos->x -= 60.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		RotateRight(30 * deltaTime);
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_pos->x += 60.0f * (float)sin((m_angle) * 180 / PI) * deltaTime;
		m_pos->y += 60.0f * (float)cos((m_angle) * 180 / PI) * deltaTime;
		//m_pos->y = yNew * deltaTime;
		//m_pos->y += 60.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		//m_pos->y -= 60.0f * deltaTime;
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
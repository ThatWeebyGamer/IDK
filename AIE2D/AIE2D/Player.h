#pragma once
#include <glm\vec2.hpp>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Player
{
public:
	Player();
	Player(glm::vec2* pos);
	~Player();

	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);

private:
	glm::vec2* m_pos;
	aie::Texture* m_texture;
	float m_angle;
	void RotateLeft(float input);
	void RotateRight(float input);
	int speed = 0;
};


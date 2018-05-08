#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"

class AIE2DApp : public aie::Application {
public:

	AIE2DApp();
	virtual ~AIE2DApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Player*				m_player;
};
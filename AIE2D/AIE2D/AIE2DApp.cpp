 #include "AIE2DApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AIE2DApp::AIE2DApp() {

}

AIE2DApp::~AIE2DApp() {

}

bool AIE2DApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_player = new Player(new glm::vec2(640, 360));

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void AIE2DApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AIE2DApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime, input);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AIE2DApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->Draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "$150 for 1080p, $300 for 2K, $600 for 4K and $900 for Full Game with complete RGB", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
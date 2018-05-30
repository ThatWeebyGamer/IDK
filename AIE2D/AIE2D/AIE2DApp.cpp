 #include "AIE2DApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <imgui.h>
#include <iostream>

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
	try
	{
		if (m_font == nullptr)
			throw 1;
	}
	catch (...)
	{
		std::cout << "could not load the texture file" << std::endl;
	}

	cookies = 0;

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

	ImGui::Begin("Visual DLC", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("1080p Resolution");
	ImGui::Button("Buy Now $150");
	ImGui::Text("2K Resolution");
	ImGui::Button("Buy Now $300");
	ImGui::Text("4K Resolution");
	ImGui::Button("Buy Now $600");
	ImGui::Text("Full Game with complete RGB");
	ImGui::Button("Buy Now $900");
	ImGui::End();

	ImGui::Begin("Gameplay DLC", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("1 Asteroid");
	ImGui::Button("Buy Now $5");
	ImGui::Text("5 Astroid");
	ImGui::Button("Buy Now $20");
	ImGui::Text("10 Astroid");
	ImGui::Button("Buy Now $35");
	ImGui::Text("50 Astroid");
	ImGui::Button("Buy Now $150");
	ImGui::Text("100 Astroid");
	ImGui::Button("Buy Now $250");
	ImGui::Text("Ability to Shoot");
	ImGui::Button("Buy Now $500");
	ImGui::Text("Remove Speed Cap");
	ImGui::Button("Buy Now $1000");
	ImGui::Text("WIN!");
	ImGui::Button("Buy Now $10000");
	ImGui::End();

	ImGui::Begin("Performance DLC", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("15 FPS");
	ImGui::Button("Buy Now $50");
	ImGui::Text("Console Peasant (30 FPS");
	ImGui::Button("Buy Now $100");
	ImGui::Text("VSync (60 FPS)");
	ImGui::Button("Buy Now $200");
	ImGui::Text("PCMasterRace (Uncapped FPS)");
	ImGui::Button("Buy Now $1000");
	ImGui::End();

	ImGui::Begin("Cookie Clicker Ripoff", 0, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize);
	if (ImGui::Button("Cookie"))
		cookies++;
	ImGui::Text("%i Cookies", cookies);
	ImGui::End();


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Microtransaction Simulator 2019", 380, 680);
	m_2dRenderer->drawText(m_font, "Press ESC to suicide", 5, 10);

	// done drawing sprites
	m_2dRenderer->end();
}
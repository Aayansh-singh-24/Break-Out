#include"Game.h"

SpriteRenderer* Renderer;

Game::Game(unsigned int width, unsigned int height)
	:state(GAME_ACTIVE), key(), Width(width), Height(height)
{

}


void Game::Init()
{
	glm::mat4 projection = glm::ortho(0.0f, float(this->Width), float(this->Height), 0.0f, 1.0f, -1.0f);
	ResourceManager::LoadShader
	(
		"D:/BreakOut/BreakOut_Project/BreakOut_Project/Engine/Graphics/Shaders/Vertex.vert",
		"D:/BreakOut/BreakOut_Project/BreakOut_Project/Engine/Graphics/Shaders/Fragment.frag",
		"Sprite"
	);

	ResourceManager::GetShader("Sprite").use().SetInteger("image", 0);
	ResourceManager::GetShader("Sprite").use().SetMatrix4("projection", projection);
	ResourceManager::LoadTexture("D:/BreakOut/Texture/awesomeface.png", true, "face");

	Renderer = new SpriteRenderer(ResourceManager::GetShader("Sprite"));
}

void Game::ProcessInput(float dt)
{

}

void Game::Update(float dt)
{

}

void Game::Render()
{
	
	Renderer->Render
	(
		ResourceManager::GetTexture("face"),
		glm::vec2(200.0f, 200.0f),
		glm::vec2(300.0f, 400.0f),
		45.0f,
		glm::vec3(1.0f, 1.0f, 1.0f)

	);
}
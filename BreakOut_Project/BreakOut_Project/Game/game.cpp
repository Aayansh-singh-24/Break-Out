#include"Game.h"



SpriteRenderer* Renderer;

GameObject* PLAYER;
glm::vec2 Player_size = glm::vec2(100.0f, 50.0f);
glm::vec2 player_velocity = glm::vec2(500.0f,0.0f);

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
	//Texture Loading:-

	ResourceManager::LoadTexture("D:/BreakOut/Texture/paddle.png", "player");
	ResourceManager::LoadTexture("D:/BreakOut/Texture/background.png", "background");
	ResourceManager::LoadTexture("D:/BreakOut/Texture/awesomeface.png", "face");
	ResourceManager::LoadTexture("D:/BreakOut/Texture/block.png", "block");
	ResourceManager::LoadTexture("D:/BreakOut/Texture/block_solid.png", "block_solid");
	//-----------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------
	


	//Levels Desiging:-
	GameLevel one;
	one.Load("D:/BreakOut/Levels/A small few gaps.lvl", this->Width, this->Height / 2);
	this->Levels.push_back(one);

	GameLevel two;
	two.Load("D:/BreakOut/Levels/Space Invader.lvl", this->Width, this->Height / 2);
	this->Levels.push_back(two);

	GameLevel three;
	three.Load("D:/BreakOut/Levels/Standard.lvl", this->Width, this->Height / 2);
	this->Levels.push_back(three);

	GameLevel four;
	four.Load("D:/BreakOut/Levels/bounce.lvl", this->Width, this->Height / 2);
	this->Levels.push_back(four);

	this->level = 3;

	Renderer = new SpriteRenderer(ResourceManager::GetShader("Sprite"));

	//----------------------------------PLAYER-CONFIGURATION------------------------------------------------
	Texture2D playerTexture = ResourceManager::GetTexture("player");
	glm::vec2 player_position = glm::vec2((this->Width / 2 - Player_size.x / 2), (this->Height - Player_size.y));
	glm::vec3 player_color = glm::vec3(1.0f);
	PLAYER = new GameObject(playerTexture, player_position, Player_size, player_color, player_velocity);

	//--------------------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------------------


}

void Game::ProcessInput(float dt)
{
	if (this->state == GAME_ACTIVE)
	{
		GLfloat velocity = player_velocity.x * dt;
		if (this->key[GLFW_KEY_A])
		{
			if (PLAYER->Position.x >= 0.0f) {
				PLAYER->Position.x -= velocity;
			}
		}

		if (this->key[GLFW_KEY_D])
		{
			if (PLAYER->Position.x <= (this->Width - Player_size.x))
				PLAYER->Position.x += velocity;

		}
	}
}

void Game::Update(float dt)
{

}

void Game::Render()
{
	// Draw background first so other sprites appear on top
	if (this->state == GAME_ACTIVE)
	{
		Texture2D backgroundTexture = ResourceManager::GetTexture("background");
		Renderer->Render
		(
			backgroundTexture,
			glm::vec2(0.0f, 0.0f),
			glm::vec2(this->Width , this->Height),
			0.0f,
			glm::vec3(1.0f, 1.0f, 1.0f)
		);

		this->Levels[this->level].draw(*Renderer);
		PLAYER->draw(*Renderer);

	}

	// Then draw other sprites
	//Renderer->Render
	//(
	//	ResourceManager::GetTexture("face"),
	//	glm::vec2(200.0f, 200.0f),
	//	glm::vec2(300.0f, 400.0f),
	//	(float)glfwGetTime(),
	//	glm::vec3(1.0f, 1.0f, 1.0f)
	//);
}
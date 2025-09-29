#pragma once

#include<glad/glad.h>
#include<glfw3.h>
#include"../Engine/Graphics/Shaders/Shader.h"
enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	GameState state;
	bool key[1024];
	unsigned int Width, Height;

	Game(const unsigned int width, const unsigned int height); // declaration the width and height of window.
	//~Game(); // Destructor(free up memory by deleteing the object)

	//Initialize GameState (load Texture , levels):-
	void Init();
	//game loop
	void ProcessInput(float deltatime);
	void Update(float deltatime);
	void Render();


};


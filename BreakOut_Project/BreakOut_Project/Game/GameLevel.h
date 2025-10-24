#pragma once
#include<vector>
#include<glm/glm.hpp>

#include <fstream>
#include <sstream>

#include"Game_object.h"
#include"../Engine/Resource/ResourceManager.h"
#include"../Engine/Renderer/Sprite/sprite.h"

class GameLevel
{
	std::vector<GameObject>Bricks; // Level State
	GameLevel() {};
	void Load(const char* file, unsigned int levelWidth, unsigned int levelHeight);
	void draw(SpriteRenderer& renderer);
	void Init(std::vector<std::vector<unsigned int>>tileData, unsigned int levelWidth, unsigned int levelHeight);

	bool IsComplete();
};
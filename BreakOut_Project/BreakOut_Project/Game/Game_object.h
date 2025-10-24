#pragma once
#include<glad/glad.h>
#include<glm/glm.hpp>

#include"../Engine/Renderer/Sprite/sprite.h"

class GameObject
{
public:
	glm::vec2 Position;
	glm::vec2 Size;
	glm::vec3 Color;
	glm::vec2 Velocity;
	float Rotation;

	bool IsDestroyed;
	bool IsSolid;

	Texture2D Sprite;
	GameObject();
	GameObject(Texture2D sprite, glm::vec2 position, glm::vec2 size, glm::vec3 color, glm::vec2 velocity);

	virtual void draw(SpriteRenderer& renderer);
};
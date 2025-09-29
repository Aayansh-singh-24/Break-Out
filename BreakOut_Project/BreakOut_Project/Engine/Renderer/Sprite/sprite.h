#pragma once
#include<glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Graphics/Shaders/Shader.h"
#include"../../Graphics/Texture/Texture.h"

class SpriteRender
{
public:
	void InitRenderData();
	void Render(Texture2D &texture, glm::vec2 size = glm::vec2(10.0f, 10.0f), glm::vec3 color = glm::vec3(1.0f),float rotation = 0.0f);
private:
	unsigned int VAO;
	glm::vec2 size = glm::vec2(10.0f, 10.0f);
	float rotate = 0.0f;
};
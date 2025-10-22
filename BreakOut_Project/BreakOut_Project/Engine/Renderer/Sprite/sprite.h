#pragma once
#include<glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Graphics/Shaders/Shader.h"
#include"../../Graphics/Texture/Texture.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader shader);


	void Render
	(
		Texture2D texture,
		glm::vec2 position = glm::vec2(0.0f, 0.0f),
		glm::vec2 size = glm::vec2(10.0f, 10.0f),
		GLfloat rotation = 0.0f,
		glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f)
	);
private:
	Shader shader;
	unsigned int VAO;
	float rotate = 0.0f;
	void InitRenderData();
};
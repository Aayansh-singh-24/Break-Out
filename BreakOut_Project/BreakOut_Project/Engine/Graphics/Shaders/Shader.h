#pragma once
#include<glad/glad.h>
#include<string>
#include<array>
#include<iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader 
{
public:

	unsigned int ID;


	Shader& use();

	void Complilation(const char* VertexShaderSource , const char* FragmentShaderSource);

//---------------------------------------------------Utility of Shaders----------------------------------------------
	void SetFloat(const char* name, float value);
	void SetInteger(const char* name, int value);
	void SetVector2f(const char* name, float x, float y);
	void SetVector2f(const char* name, glm::vec2& value);
	void SetVector3f(const char* name, float x, float y, float z);
	void SetVector3f(const char* name, glm::vec3& value);
	void SetMatrix4(const char* name, glm::mat4& value);

private:
	void Compilation_CheckUp(int object, std::string msg)
	{
		int success;
		char infoLog[1024];
		if (msg == "VERTEX")
		{
			glGetShaderiv(object, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(object, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER::"<<msg<<"::COMPILATION_FAILED\n" << infoLog << std::endl;
			};

			glGetShaderiv(object, GL_COMPILE_STATUS, &success);

		}
		else if (msg == "FRAGMENT")
		{
			glGetShaderiv(object, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(object, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER::" << msg << "::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}
		else if (msg == "PROGRAM")
		{
			glGetProgramiv(object, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(object, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER::" << msg << "::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}
	}
};

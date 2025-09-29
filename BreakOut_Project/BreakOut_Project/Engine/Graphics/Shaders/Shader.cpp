#include"Shader.h"

Shader& Shader::use()
{
	glUseProgram(this->ID);
	return *this;
}
void Shader::Complilation(const char* VertexShaderSource, const char* FragmnetShaderSource)
{
	
	unsigned int VertexShader=  glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &VertexShaderSource, NULL);
	glCompileShader(VertexShader);
	Compilation_CheckUp(VertexShader, "VERTEX");

	unsigned int FragmnetShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmnetShader, 1, &FragmnetShaderSource, NULL);
	glCompileShader(FragmnetShader);
	Compilation_CheckUp(FragmnetShader, "FRAGMENT");

	//Linking:-
	this->ID = glCreateProgram();
	glAttachShader(this->ID, VertexShader);
	glAttachShader(this->ID, FragmnetShader);
	glLinkProgram(this->ID);
	Compilation_CheckUp(this->ID, "PROGRAM");


	glDeleteShader(VertexShader);
	glDeleteShader(FragmnetShader);

}

//------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------//

//Defination of Utilities , which helps to use opengl concepts.

void Shader::SetFloat(const char* name,float value)
{
    glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetInteger(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::SetVector2f(const char* name, float x, float y)
{
	glUniform2f(glGetUniformLocation(this->ID, name), x,y);
}

void Shader::SetVector3f(const char* name, float x, float y,float z)
{
	glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::SetVector2f(const char* name, glm::vec2 &value)
{
	glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
}

void Shader::SetVector3f(const char* name, glm::vec3& value)
{
	glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::SetMatrix4(const char* name, glm::mat4& value)
{
	glUniformMatrix4fv(glGetUniformLocation(this->ID, name), 1, false, glm::value_ptr(value));
}
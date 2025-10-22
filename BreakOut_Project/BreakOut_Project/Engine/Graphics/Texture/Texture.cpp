#include"Texture.h"

Texture2D::Texture2D()
	:nrChannels(GL_RGB), image_format(GL_RGB), Width(0), Height(0), 
	wrap_s(GL_TEXTURE_WRAP_S), wrap_t(GL_TEXTURE_WRAP_T), 
	filter_min(GL_LINEAR),
	filter_max(GL_LINEAR)
{
	glGenTextures(1,&this->ID);
}

void Texture2D::Generate(unsigned int width, unsigned int height, unsigned char* data)
{
	// For future use like scalling , debugging..
	this->Width = width;
	this->Height = height;

	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, this->image_format, width, height, 0, this->image_format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_max);

	// unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);

}

void Texture2D::bind()
{
	glBindTexture(GL_TEXTURE_2D, this->ID);
}
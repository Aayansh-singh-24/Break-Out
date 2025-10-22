#pragma once

#include <glad/glad.h>

class Texture2D
{
public:
	unsigned int ID;  

	unsigned int nrChannels;
	// width and height of loaded image in pixels
	unsigned int Width;
	unsigned int Height;

	//Texture Configuration:
	unsigned int image_format; // format of image like png,jpg etc
	unsigned int wrap_s; //Wrapping around horizontal axis
	unsigned int wrap_t; //Wrapping around vertical axis
	unsigned int filter_min; // filtering mode if texture pixels < screen pixels
	unsigned int filter_max; // // filtering mode if texture pixels > screen pixels

	//Constructor:
	Texture2D();

	void Generate(unsigned int width , unsigned int height , unsigned char* data);
	void bind();


};

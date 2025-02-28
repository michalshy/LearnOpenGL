#ifndef LESSONTEXTURES_HPP
#define LESSONTEXTURES_HPP


#include "Lesson.hpp"

#include "stb_image.h"

class LessonTextures : public Lesson
{
	Shader shader;
	unsigned int tex, texF, VAO, VBO, EBO;
public:
	LessonTextures() : 
		shader("shaders\\shTex.vert", "shaders\\shTex.frag"), 
		tex(0), 
		texF(0), 
		VAO(0), 
		VBO(0), 
		EBO(0) 
	{}
	void init();
	void run();
};

#endif


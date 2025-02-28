#ifndef LESSON_H
#define LESSON_H
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "stb_image.h"


class Lesson {
public:
	virtual void init() = 0;
	virtual void run() = 0;
};

#endif

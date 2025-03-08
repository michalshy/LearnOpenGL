#ifndef LESSON_H
#define LESSON_H
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Camera.hpp"

class Lesson {
public:
	virtual void init() = 0;
	virtual void run() = 0;
};

#endif

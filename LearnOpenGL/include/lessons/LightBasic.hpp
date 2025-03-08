#ifndef LIGHTBASIC_HPP
#define LIGHTBASIC_HPP

#include "Lesson.hpp"

class LightBasic :
    public Lesson
{
	Shader lighting;
	Shader lightSource;
	unsigned int VAO, VBO, lightVAO;
	GLFWwindow* window;

public:
	LightBasic(GLFWwindow* _window) :
		lighting("shaders\\light\\basic\\sh.vert", "shaders\\light\\basic\\sh.frag"),
		lightSource("shaders\\light\\basic\\sh.vert", "shaders\\light\\basic\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		window(_window)
	{
	}
	void init();
	void run();
};

#endif


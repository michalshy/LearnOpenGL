#ifndef LIGHTCOLOR_HPP
#define LIGHTCOLOR_HPP

#include "Lesson.hpp"

class LightColor :
    public Lesson
{
	Shader lighting;
	Shader lightSource;
    unsigned int VAO, VBO, lightVAO;
    GLFWwindow* window;

public:
	LightColor(GLFWwindow* _window) :
		lighting("shaders\\light\\color\\sh.vert", "shaders\\light\\color\\sh.frag"),
		lightSource("shaders\\light\\color\\sh.vert", "shaders\\light\\color\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		window(_window)
	{}
    void init();
    void run();
};


#endif // !LIGHTCOLOR_HPP



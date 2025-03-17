#ifndef LIGHTMATERIALS_HPP
#define LIGHTMATERIALS_HPP

#include "Lesson.hpp"

class LightMaterial :
    public Lesson
{
	Shader lighting;
	Shader lightSource;
	unsigned int VAO, VBO, lightVAO;
	GLFWwindow* window;

public:
	LightMaterial(GLFWwindow* _window) :
		lighting("shaders\\light\\materials\\sh.vert", "shaders\\light\\materials\\sh.frag"),
		lightSource("shaders\\light\\materials\\shLight.vert", "shaders\\light\\materials\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		window(_window)
	{
	}
	void init();
	void run();
};


#endif // !1



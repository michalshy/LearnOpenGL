#ifndef LIGHTFINAL_HPP
#define LIGHTFINAL_HPP

#include "Lesson.hpp"

class LightFinal :
    public Lesson
{
	Shader lighting;
	Shader lightSource;
	unsigned int VAO, VBO, lightVAO, tex, texSpec;
	GLFWwindow* window;
public:
	LightFinal(GLFWwindow* _window) :
		lighting("shaders\\light\\final\\sh.vert", "shaders\\light\\final\\sh.frag"),
		lightSource("shaders\\light\\final\\shLight.vert", "shaders\\light\\final\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		texSpec(0),
		window(_window)
	{}
    void init();
    void run();
protected:
	unsigned int load_texture(char const* path);
};

#endif


#ifndef LIGHTCASTERS_HPP
#define LIGHTCASTERS_HPP

#include "Lesson.hpp"
class LightCasters :
    public Lesson
{
	Shader lighting;
	Shader lightSource;
	unsigned int VAO, VBO, lightVAO, tex, texSpec, texEmission;
	GLFWwindow* window;
public:
	LightCasters(GLFWwindow* _window) :
		lighting("shaders\\light\\casters\\sh.vert", "shaders\\light\\casters\\sh.frag"),
		lightSource("shaders\\light\\casters\\shLight.vert", "shaders\\light\\casters\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		texSpec(0),
		texEmission(0),
		window(_window)
	{}
	void init();
	void run();
protected:
	unsigned int load_texture(char const* path);
};

#endif


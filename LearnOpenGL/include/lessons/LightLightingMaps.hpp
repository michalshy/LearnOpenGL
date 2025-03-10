#ifndef LIGHTLIGHTINGMAPS_HPP
#define LIGHTLIGHTINGMAPS_HPP

#include "Lesson.hpp"

class LightLightingMaps : public Lesson
{
	Shader lighting;
	Shader lightSource;
	unsigned int VAO, VBO, lightVAO, tex;
	GLFWwindow* window;

public:
	LightLightingMaps(GLFWwindow* _window) :
		lighting("shaders\\light\\lightingmaps\\sh.vert", "shaders\\light\\lightingmaps\\sh.frag"),
		lightSource("shaders\\light\\lightingmaps\\shLight.vert", "shaders\\light\\lightingmaps\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		window(_window)
	{}
	void init();
	void run();
protected:
	unsigned int load_texture(char const* path);
};

#endif


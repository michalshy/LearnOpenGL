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
	//directional
	/*LightCasters(GLFWwindow* _window) :
		lighting("shaders\\light\\casters\\directional\\sh.vert", "shaders\\light\\casters\\directional\\sh.frag"),
		lightSource("shaders\\light\\casters\\directional\\shLight.vert", "shaders\\light\\casters\\directional\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		texSpec(0),
		texEmission(0),
		window(_window)
	{}*/

	//point
	/*LightCasters(GLFWwindow* _window) :
		lighting("shaders\\light\\casters\\point\\sh.vert", "shaders\\light\\casters\\point\\sh.frag"),
		lightSource("shaders\\light\\casters\\point\\shLight.vert", "shaders\\light\\casters\\point\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		texSpec(0),
		texEmission(0),
		window(_window)
	{}*/
	LightCasters(GLFWwindow* _window) :
		lighting("shaders\\light\\casters\\spot\\sh.vert", "shaders\\light\\casters\\spot\\sh.frag"),
		lightSource("shaders\\light\\casters\\spot\\shLight.vert", "shaders\\light\\casters\\spot\\shLight.frag"),
		VAO(0),
		VBO(0),
		lightVAO(0),
		tex(0),
		texSpec(0),
		texEmission(0),
		window(_window)
	{
	}
	void init();
	void run();
protected:
	unsigned int load_texture(char const* path);
};

#endif


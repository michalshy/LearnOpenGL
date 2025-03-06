#ifndef LESSONCAMERA_HPP
#define LESSONCAMERA_HPP

#include "Lesson.hpp"

class LessonCamera :
	public Lesson
{
	Shader shader;
	unsigned int tex, texF, VAO, VBO;
	GLFWwindow* window;

	
public:
	LessonCamera(GLFWwindow* _window) :
		shader("shaders\\cords\\sh.vert", "shaders\\cords\\sh.frag"),
		tex(0),
		texF(0),
		VAO(0),
		VBO(0),
		window(_window)
	{}
	void init();
	void run();
protected:
	void additional_input();
};

#endif // !LESSONCAMERA_HPP



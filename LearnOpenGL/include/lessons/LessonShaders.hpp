#ifndef LESSONHADER_HPP
#define LESSONHADER_HPP

#include "Lesson.hpp"

class LessonShaders : Lesson{
	Shader sF;
	Shader sS;
	unsigned int VBO1, VBO2, VAO1, VAO2;
public:
	LessonShaders() : sF("shaders\\sh.vert", "shaders\\sh1.frag"), sS("shaders\\sh.vert", "shaders\\sh2.frag") {}
	void init();
	void run();
};





#endif
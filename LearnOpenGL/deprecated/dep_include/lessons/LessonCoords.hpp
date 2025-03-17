#ifndef LESSONCOORDS_HPP
#define LESSONCOORDS_HPP

#include "Lesson.hpp"

class LessonCoords :
    public Lesson
{
    Shader shader;
    unsigned int tex, texF, VAO, VBO;
public:
    LessonCoords() :
		shader("shaders\\cords\\sh.vert", "shaders\\cords\\sh.frag"),
		tex(0),
		texF(0),
		VAO(0),
		VBO(0)
	{ }
    void init();
    void run();
};

#endif // !



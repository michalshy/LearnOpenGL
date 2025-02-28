#ifndef LESSONTRANSFORMATION_HPP
#define LESSONTRANSFORMATION_HPP

#include "Lesson.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class LessonTransformation :
    public Lesson
{
	Shader shader;
	unsigned int tex, texF, VAO, VBO, EBO;
public:
    LessonTransformation() :
		shader("shaders\\transform\\sh.vert", "shaders\\transform\\sh.frag"),
		tex(0),
		texF(0),
		VAO(0),
		VBO(0),
		EBO(0)
	{ }
    void init();
    void run();
};

#endif


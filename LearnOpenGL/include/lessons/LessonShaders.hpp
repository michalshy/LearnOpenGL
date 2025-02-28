#ifndef LESSONHADER_HPP
#define LESSONHADER_HPP
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "Lesson.hpp"

class LessonShaders : Lesson{
	Shader sF;
	Shader sS;
	unsigned int VBO1, VBO2, VAO1, VAO2;
public:
	LessonShaders() : sF("shaders\\sh.vert", "shaders\\sh1.frag"), sS("shaders\\sh.vert", "shaders\\sh2.frag") {}
	void init()
	{
		float first[] = {
			//positions		  //colors
		 0.2f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // right top
		 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // right bottom right
		 0.2f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, };  // right bottom left
		float second[] = {
		-0.2f,  -0.5f, 0.0f,   // left bottom right
		-0.5f,  -0.5f, 0.0f,   // left bottom left
		-0.2f,  0.5f, 0.0f,   // left top
		};
		//unsigned int indices[] = {  // note that we start from 0!
		//	0, 1, 2,   // first triangle
		//	3, 4, 5    // second triangle
		//};

		glGenBuffers(1, &VBO1);
		glGenVertexArrays(1, &VAO1);
		glBindVertexArray(VAO1);
		glBindBuffer(GL_ARRAY_BUFFER, VBO1);
		glBufferData(GL_ARRAY_BUFFER, sizeof(first), first, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		glGenBuffers(1, &VBO2);
		glGenVertexArrays(1, &VAO2);
		glBindVertexArray(VAO2);
		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(second), second, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		int nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
	}

	void run()
	{
		sF.use();
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		float timeValue = glfwGetTime();
		float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
		sS.use();
		sS.set4Float("ourColor", 0.0f, greenValue, 0.0f, 1.0f);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
};





#endif
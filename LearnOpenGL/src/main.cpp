#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "LessonShaders.hpp"
#include "LessonTextures.hpp"
#include "LessonTransformation.hpp"
#include "LessonCoords.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Setup GLFW Window
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Setup GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to init GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);	

	// LESSONS
	//LessonShaders lSh;
	//LessonTextures lTex(window);
	//LessonTransformation lTrans;
	LessonCoords lCoords;
	//lTrans.init();
	//lSh.init();
	//lTex.init();
	lCoords.init();

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.f, 0.2f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		//lSh.run();
		//lTex.run();
		//lTrans.run();
		lCoords.run();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
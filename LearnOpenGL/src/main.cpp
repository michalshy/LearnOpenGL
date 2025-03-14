#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include "shader/Shader.h"
#include "LessonShaders.hpp"
#include "LessonTextures.hpp"
#include "LessonTransformation.hpp"
#include "LessonCoords.hpp"
#include "LessonCamera.hpp"
#include "LightColor.hpp"
#include "LightBasic.hpp"
#include "LightMaterial.hpp"
#include "LightLightingMaps.hpp"
#include "LightCasters.hpp"
#include "LightFinal.hpp"

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
	//LessonCoords lCoords;
	//LessonCamera lCam(window);
	//lTrans.init();
	//lSh.init();
	//lTex.init();
	//lCoords.init();
	//lCam.init();

	//LightColor lC(window);
	//lC.init();
	//LightBasic lB(window);
	//lB.init();
	//LightMaterial lm(window);
	//lm.init();
	//LightLightingMaps lMm(window);
	//lMm.init();
	//LightCasters lCast(window);
	//lCast.init();
	LightFinal lightFinal(window);
	lightFinal.init();

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.1f, 0.1f, 0.1f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//lSh.run();
		//lTex.run();
		//lTrans.run();
		//lCoords.run();
		//lCam.run();

		//lC.run();
		//lB.run();
		//lm.run();
		//lMm.run();
		//lCast.run();
		lightFinal.run();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource1 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
"}\n\0";

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

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	int successVer;
	char infoLogVer[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &successVer);
	if (!successVer)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLogVer);
		std::cout << "Error: Vertex shader compilation failed\n" << infoLogVer << std::endl;
	}

	unsigned int fragmentShader1;
	fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
	glCompileShader(fragmentShader1);

	int successFrag;
	char infoLogFrag[512];
	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &successFrag);
	if (!successFrag)
	{
		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLogFrag);
		std::cout << "Error: Vertex shader compilation failed\n" << infoLogFrag << std::endl;
	}

	unsigned int fragmentShader2;
	fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
	glCompileShader(fragmentShader2);

	int successFrag2;
	char infoLogFrag2[512];
	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &successFrag2);
	if (!successFrag2)
	{
		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLogFrag2);
		std::cout << "Error: Vertex shader compilation failed\n" << infoLogFrag2 << std::endl;
	}

	unsigned int shaderProgram1;
	shaderProgram1 = glCreateProgram();
	glAttachShader(shaderProgram1, vertexShader);
	glAttachShader(shaderProgram1, fragmentShader1);
	glLinkProgram(shaderProgram1);

	unsigned int shaderProgram2;
	shaderProgram2 = glCreateProgram();
	glAttachShader(shaderProgram2, vertexShader);
	glAttachShader(shaderProgram2, fragmentShader2);
	glLinkProgram(shaderProgram2);

	int successLink1;
	char infoLogLink1[512];
	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &successLink1);
	if (!successLink1) {
		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLogLink1);
		std::cout << "Error: Vertex shader compilation failed\n" << infoLogLink1 << std::endl;
	}

	int successLink2;
	char infoLogLink2[512];
	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &successLink2);
	if (!successLink2) {
		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLogLink2);
		std::cout << "Error: Vertex shader compilation failed\n" << infoLogLink2 << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader1);
	glDeleteShader(fragmentShader2);

	float first[] = {
	 0.2f,  0.5f, 0.0f,  // right top
	 0.5f, -0.5f, 0.0f,  // right bottom right
	 0.2f, -0.5f, 0.0f };  // right bottom left
	float second[] = {
	- 0.2f,  -0.5f, 0.0f,   // left bottom right
	-0.5f,  -0.5f, 0.0f,   // left bottom left
	-0.2f,  0.5f, 0.0f,   // left top
	};
	//unsigned int indices[] = {  // note that we start from 0!
	//	0, 1, 2,   // first triangle
	//	3, 4, 5    // second triangle
	//};

	unsigned int VBO1, VBO2, VAO1, VAO2;
	glGenBuffers(1, &VBO1);
	glGenVertexArrays(1, &VAO1);
	glBindVertexArray(VAO1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(first), first, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
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
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.f, 1.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram1);
		glBindVertexArray(VAO1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glUseProgram(shaderProgram2);
		glBindVertexArray(VAO2);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
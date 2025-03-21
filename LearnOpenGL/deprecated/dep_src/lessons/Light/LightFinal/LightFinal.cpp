#include "LightFinal.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);

// settings
constexpr unsigned int SCR_WIDTH = 800;
constexpr unsigned int SCR_HEIGHT = 600;

static Camera cam(glm::vec3(1.0f, 2.0f, 6.0f), glm::vec3(0.f, 1.f, 0.f), -90, -20);
static float lastX = SCR_WIDTH / 2.0f;
static float lastY = SCR_HEIGHT / 2.0f;
static bool firstMouse = true;

static float deltaTime = 0.f;
static float lastFrame = 0.f;

static glm::vec3 pointLightPositions[] =
{
	glm::vec3(0.7f, 0.2f, 2.0f),
	glm::vec3(2.3f, -3.3f, -4.0f),
	glm::vec3(-4.f, 2.0f, -12.0f),
	glm::vec3(0.f, 0.0f, -3.0f)
};

static constexpr glm::vec3 cubePositions[] =
{
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
};

void LightFinal::init()
{
	tex = load_texture("tex\\container2.png");
	texSpec = load_texture("tex\\container2_specular.png");

	float vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	lighting.use();

	//attach texture
	lighting.setInt("material.diffuse", 0);
	lighting.setInt("material.specular", 1);
	lighting.setInt("material.emission", 2);

	lighting.setFloat("material.shininess", 32.0f);

	//directional
	//lighting.setVec3("light.direction", -0.2f, -1.f, -0.3f);

	//glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f); - ortographic projection matrix
	//glm::mat4 proj = glm::perspective(glm::radians(45.0f), (float)width/(float)height, 0.1f, 100.0f); - perspective projection matrix

	//enable z buff
	glEnable(GL_DEPTH_TEST);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void LightFinal::run()
{
	processInput(window);

	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	lighting.use();

	//setting lights
	lighting.setVec3("viewPos", cam.Position);
	//point

	//directional
	lighting.setVec3("dirLight.direction", -0.2f, -1.f, -0.3f);
	lighting.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
	lighting.setVec3("dirLight.diffuse", 0.2f, 0.2f, 0.2f); // darken diffuse light a bit
	lighting.setVec3("dirLight.specular", 1.0f, 1.0f, 1.0f);

	//spotlight
	lighting.setVec3("spotLight.position", cam.Position);
	lighting.setVec3("spotLight.direction", cam.Front);
	lighting.setVec3("spotLight.ambient", 0.1f, 0.1f, 0.1f);
	lighting.setVec3("spotLight.diffuse", 0.8f, 0.8f, 0.8f); // darken diffuse light a bit
	lighting.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
	lighting.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
	lighting.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(20.f)));
	lighting.setFloat("spotLight.constant", 1.0f);
	lighting.setFloat("spotLight.linear", 0.09f);
	lighting.setFloat("spotLight.quadratic", 0.032f);

	//for point light
	lighting.setVec3("pointLights[0].position", pointLightPositions[0]);
	lighting.setVec3("pointLights[0].ambient", 0.1f, 0.1f, 0.1f);
	lighting.setVec3("pointLights[0].diffuse", 0.4f, 0.4f, 0.4f); // darken diffuse light a bit
	lighting.setVec3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
	lighting.setFloat("pointLights[0].constant", 1.0f);
	lighting.setFloat("pointLights[0].linear", 0.09f);
	lighting.setFloat("pointLights[0].quadratic", 0.032f);
	lighting.setVec3("pointLights[1].position", pointLightPositions[1]);
	lighting.setVec3("pointLights[1].ambient", 0.1f, 0.1f, 0.1f);
	lighting.setVec3("pointLights[1].diffuse", 0.4f, 0.4f, 0.4f); // darken diffuse light a bit
	lighting.setVec3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
	lighting.setFloat("pointLights[1].constant", 1.0f);
	lighting.setFloat("pointLights[1].linear", 0.09f);
	lighting.setFloat("pointLights[1].quadratic", 0.032f);
	lighting.setVec3("pointLights[2].position", pointLightPositions[2]);
	lighting.setVec3("pointLights[2].ambient", 0.1f, 0.1f, 0.1f);
	lighting.setVec3("pointLights[2].diffuse", 0.4f, 0.4f, 0.4f); // darken diffuse light a bit
	lighting.setVec3("pointLights[2].specular", 0.8f, 0.8, 0.8);
	lighting.setFloat("pointLights[2].constant", 1.0f);
	lighting.setFloat("pointLights[2].linear", 0.09f);
	lighting.setFloat("pointLights[2].quadratic", 0.032f);
	lighting.setVec3("pointLights[3].position", pointLightPositions[3]);
	lighting.setVec3("pointLights[3].ambient", 0.1f, 0.1f, 0.1f);
	lighting.setVec3("pointLights[3].diffuse", 0.3f, 0.3f, 0.3f); // darken diffuse light a bit
	lighting.setVec3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
	lighting.setFloat("pointLights[3].constant", 1.0f);
	lighting.setFloat("pointLights[3].linear", 0.09f);
	lighting.setFloat("pointLights[3].quadratic", 0.032f);


	//setting up camera
	glm::mat4 projection = glm::perspective(glm::radians(cam.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.f);
	glm::mat4 view = cam.GetViewMatrix();
	lighting.setMat4("projection", projection);
	lighting.setMat4("view", view);

	//rotation and translation
	glm::mat4 model = glm::mat4(1.f);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texSpec);

	for (unsigned int i = 0; i < 10; i++)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.f * i;
		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.f, 0.3f, 0.5f));
		lighting.setMat4("model", model);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	//draw light
	lightSource.use();
	lightSource.setMat4("projection", projection);
	lightSource.setMat4("view", view);

	for (int i = 0; i < 4; i++)
	{

		model = glm::mat4(1.0f);
		model = glm::translate(model, pointLightPositions[i]);
		model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
		lightSource.setMat4("model", model);
		glBindVertexArray(lightVAO);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}


	glBindVertexArray(0);
}

unsigned int LightFinal::load_texture(char const* path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrChannels;
	unsigned char* data;
	data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{
		GLenum format;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	else
	{
		std::cout << "Failed to load tex" << std::endl;
	}
	stbi_image_free(data);
	return textureID;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
static void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cam.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cam.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cam.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cam.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	cam.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	cam.ProcessMouseScroll(static_cast<float>(yoffset));
}


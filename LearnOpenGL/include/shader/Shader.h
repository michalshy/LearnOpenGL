#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	//the program ID
	unsigned int ID;

	// constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);
	// use/activate the shader
	void use();
	//utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void set4Float(const std::string& name, float x, float y, float z, float w) const;
	void setMat4(const std::string& name, glm::mat4&);
	void setVec3(const std::string& name, float x, float y, float z) const;
	void setVec3(const std::string& name, glm::vec3&) const;
};

#endif // !SHADER_H


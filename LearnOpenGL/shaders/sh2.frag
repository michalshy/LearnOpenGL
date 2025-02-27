#version 330 core
out vec4 FragColor;
in vec3 vertexColor;
in vec3 verPos; 
uniform vec4 ourColor;
void main()
{
   FragColor = vec4(verPos, 1.0);
}
#pragma once

#include <glad/glad.h>

class Shape
{
public:
	Shape(float vertices[], size_t verticesSize, int indices[], size_t indicesSize, float texCoords[], size_t texCoordsSize); // type of sizeof(x) is size_t
	~Shape();

	unsigned int GetVao() { return m_vao; }
	unsigned int GetTbo() { return m_tbo; }
	int GetNumVertices() { return (int)(m_indicesSize / sizeof(int)); }
	size_t m_texCoordsSize;
	
private:
	unsigned int m_vao, m_vbo, m_tbo, m_ibo;
	size_t m_indicesSize;
};

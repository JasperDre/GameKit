/*
 * =====================================================================================
 *
 *       Filename:  RectangleShape.cpp
 *
 *    Description:
 *
 *        Created:  27/09/2014 17:06:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>

#include "gk/gl/Shader.hpp"
#include "gk/gl/Vertex.hpp"
#include "gk/graphics/RectangleShape.hpp"

namespace gk {

RectangleShape::RectangleShape(float width, float height, const Color &color) {
	m_color = color;

	setSize(width, height);

	for (u8 i = 1 ; i < 5 ; ++i) {
		for (u8 j = 0 ; j < 6 ; ++j) {
			m_indices[i * 6 + j] = m_indices[j] + 4 * i;
		}
	}
}

void RectangleShape::updateVertexBuffer() const {
	float o = m_outlineThickness;
	Vertex vertices[4 + 4 * 4] = {
		// Rectangle vertices
		{{m_width, 0,        0, -1}},
		{{0,       0,        0, -1}},
		{{0,       m_height, 0, -1}},
		{{m_width, m_height, 0, -1}},

		// Top outline
		{{m_width + o, -o,   0, -1}},
		{{-o,          -o,   0, -1}},
		{{-o,          0,    0, -1}},
		{{m_width + o, 0,    0, -1}},

		// Bottom outline
		{{m_width + o, m_height,     0, -1}},
		{{-o,          m_height,     0, -1}},
		{{-o,          m_height + o, 0, -1}},
		{{m_width + o, m_height + o, 0, -1}},

		// Left outline
		{{0,      0,        0, -1}},
		{{-o,     0,        0, -1}},
		{{-o,     m_height, 0, -1}},
		{{0,      m_height, 0, -1}},

		// Right outline
		{{m_width,      0,        0, -1}},
		{{m_width + o,  0,        0, -1}},
		{{m_width + o,  m_height, 0, -1}},
		{{m_width,      m_height, 0, -1}},
	};

	for (u8 i = 0 ; i < 4 ; ++i) {
		vertices[i].color[0] = m_color.r;
		vertices[i].color[1] = m_color.g;
		vertices[i].color[2] = m_color.b;
		vertices[i].color[3] = m_color.a;
	}

	for (u8 i = 4 ; i < 4 + 4 * 4 ; ++i) {
		vertices[i].color[0] = m_outlineColor.r;
		vertices[i].color[1] = m_outlineColor.g;
		vertices[i].color[2] = m_outlineColor.b;
		vertices[i].color[3] = m_outlineColor.a;
	}

	VertexBuffer::bind(&m_vbo);
	m_vbo.setData(sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	VertexBuffer::bind(nullptr);
}

void RectangleShape::draw(RenderTarget &target, RenderStates states) const {
	states.transform *= getTransform();

	states.vertexAttributes = VertexAttribute::Only2d;

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	if(m_wireframeMode) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	target.drawElements(m_vbo, GL_TRIANGLES, 6 * 5, GL_UNSIGNED_BYTE, m_indices, states);
	if(m_wireframeMode) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

} // namespace gk


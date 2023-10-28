#include "Entity.h"

Entity::Entity(const std::string& texturePath, glm::vec3 position, float rotationAngle, glm::vec2 scale) :
	Position(position)
{
	m_entityData = std::make_shared<EntityData>(texturePath);
	r_rotAngle = rotationAngle;
	Scale = scale;
	m_rotOrig = glm::vec3(0, 0, 0);
}

Entity::Entity() :
	Position(glm::vec3(0, 0, 0)), r_rotAngle(0.0f), Scale(glm::vec2(100, 100))
{
	m_entityData = std::make_shared<EntityData>("");
}

/// <summary>
/// Setups up and sends all the stuff to the gpu
/// </summary>
void Entity::Render(Shader* shader)
{
	m_model = glm::mat4(1.0f);
	m_model = glm::translate(m_model, m_rotOrig);
	m_model = glm::rotate(m_model, glm::radians(r_rotAngle), glm::vec3(0, 0, 1));
	m_model = glm::translate(m_model, Position);
	m_model = glm::scale(m_model, glm::vec3(Scale, 1));

	shader->LoadMat4("model", m_model);
	shader->LoadInt("spriteSheetRows", 0);
	shader->LoadInt("spriteSheetColumns", 0);
	shader->LoadInt("time", 0);

	glDrawElements(GL_TRIANGLES, m_entityData->GetShape()->GetNumVertices(), GL_UNSIGNED_INT, 0);
}

/// <summary>
/// Rotates about the point (relative) specified.
/// Angle in degree
/// </summary>
void Entity::RotateAbout(float angle, glm::vec2 relPos)
{
	r_rotAngle = angle;
	m_rotOrig = glm::vec3(relPos.x, relPos.y, 0);
}

bool Entity::CollidesWith(const Entity& other)
{
	if (std::fabs(Position.x - other.Position.x) < Scale.x / 2.f + other.Scale.x / 2.f) {
		if (std::fabs(Position.y - other.Position.y) < Scale.y / 2.f + other.Scale.y / 2.f) {
			return true;
		}
	}
	return false;
}

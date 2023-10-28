#pragma once

#include <glm/glm.hpp>
#include "EntityData.h"
#include "Shader.h"

class Entity
{
public:
	Entity(const std::string& texturePath, glm::vec3 position, float rotationAngle = 0, glm::vec2 scale = glm::vec2(50, 50));
	Entity();

	glm::vec3 Position;
	glm::vec2 Scale;

	std::shared_ptr<EntityData> GetEntityData() { return m_entityData; }
	virtual void Render(Shader* shader);

	void RotateAbout(float angle, glm::vec2 relPos);

	bool CollidesWith(const Entity& other);
private:
	float r_rotAngle;
	glm::vec3 m_rotOrig;
	std::shared_ptr<EntityData> m_entityData;
	glm::mat4 m_model;
};

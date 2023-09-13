#pragma once

#include "Scene.h"

class ProjectileScene : public Scene
{
public:
	ProjectileScene();
	virtual ~ProjectileScene() override;

	virtual void Render() override;
	virtual void Update(float dt) override;
private:
	Entity* m_entity;
	MasterRenderer* m_renderer;

	glm::vec2 acceleration = glm::vec2(0.f, -9.8f * 100.f);
	glm::vec2 velocity = glm::vec2(700.f, 700.f);

	void CleanUp();
};

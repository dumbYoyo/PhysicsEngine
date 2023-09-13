#include "ProjectileScene.h"

ProjectileScene::ProjectileScene()
{
	m_entity = new Entity("res/Ball.png", glm::vec3(50, 150, 0), 0.f, glm::vec2(50, 50));
	m_renderer = new MasterRenderer();
}

ProjectileScene::~ProjectileScene() { CleanUp(); }

void ProjectileScene::Render()
{
	m_renderer->AddEntity(m_entity);
	m_renderer->Render();
}

void ProjectileScene::Update(float dt)
{
	velocity.y += acceleration.y * dt;

	m_entity->Position.y += velocity.y * dt;
	m_entity->Position.x += velocity.x * dt;
}

void ProjectileScene::CleanUp()
{
	delete m_renderer;
	delete m_entity;
}

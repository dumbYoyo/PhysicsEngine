#include "ProjectileScene.h"

ProjectileScene::ProjectileScene()
{
	m_entity = new Entity("res/pic.png", glm::vec3(200, 400, 0), 0.f, glm::vec2(200, 550));
	m_renderer = new MasterRenderer();
}

ProjectileScene::~ProjectileScene() { CleanUp(); }

void ProjectileScene::Render()
{
	m_renderer->AddEntity(m_entity);
	m_renderer->Render();
}

void ProjectileScene::Update(float dt) {}

void ProjectileScene::CleanUp()
{
	delete m_renderer;
	delete m_entity;
}

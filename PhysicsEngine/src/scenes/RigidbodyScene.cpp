#include "RigidbodyScene.h"

RigidbodyScene::RigidbodyScene()
{
	m_ent = new Entity("res/Ball.png", glm::vec3(50, 150, 0));
	m_renderer = new MasterRenderer();
	angle = 0.f;
}

RigidbodyScene::~RigidbodyScene()
{
}

void RigidbodyScene::Render()
{
	m_renderer->AddEntity(m_ent);
	m_renderer->Render();
}

void RigidbodyScene::Update(float dt)
{
	m_ent->RotateAbout(angle, glm::vec2(1280 / 2, 720 / 2));
	angle += 100 * dt;
}

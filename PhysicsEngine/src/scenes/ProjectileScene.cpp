#include "ProjectileScene.h"

ProjectileScene::ProjectileScene()
{
	m_entity = new Entity("res/Ball.png", glm::vec3(50, 150, 0));
	m_renderer = new MasterRenderer();
	m_pause = true;

	InitImgui(m_window);
}

ProjectileScene::~ProjectileScene() { CleanUp(); }

void ProjectileScene::Render()
{
	m_renderer->AddEntity(m_entity);
	m_renderer->Render();

	StartFrameImgui();

	ImGui::Begin("Control");
	if (ImGui::Button("Play") && m_pause)
		m_pause = false;
	if (ImGui::Button("Reset"))
	{
		m_pause = true;
		velocity.y = 700.f;
		velocity.x = 700.f;
		m_entity->Position.x = 50;
		m_entity->Position.y = 150;
	}
	ImGui::End();

	EndFrameImgui();
}

void ProjectileScene::Update(float dt)
{
	if (m_pause)
		return;

	velocity.y += acceleration.y * dt;

	m_entity->Position.y += velocity.y * dt;
	m_entity->Position.x += velocity.x * dt;
}

void ProjectileScene::CleanUp()
{
	delete m_renderer;
	delete m_entity;
	DestroyImgui();
}

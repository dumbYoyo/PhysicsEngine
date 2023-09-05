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

	void CleanUp();
};

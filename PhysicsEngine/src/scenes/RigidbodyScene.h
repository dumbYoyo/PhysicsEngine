#pragma once

#include "Scene.h"

class RigidbodyScene : public Scene
{
public:
	RigidbodyScene();
	virtual ~RigidbodyScene() override;

	virtual void Render() override;
	virtual void Update(float dt) override;

private:
	Entity* m_ent;
	float angle;
	MasterRenderer* m_renderer;
};
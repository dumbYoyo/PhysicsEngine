#pragma once

#include "core/Window.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Run();
private:
	GLFWwindow* m_window;

	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
};

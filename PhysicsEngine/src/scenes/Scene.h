#pragma once

#include "core/Window.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void Run();
private:
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
protected:
	GLFWwindow* m_window;
};

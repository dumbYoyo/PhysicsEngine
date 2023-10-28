#include "Scene.h"

Scene::Scene()
{
	m_window = CreateWindow(1280, 720, "Physics Engine");
}

Scene::~Scene() { glfwTerminate(); }

void Scene::Run()
{
	double previous = glfwGetTime();
	double secsPerUpdate = 1.0 / 60.0;
	double steps = 0.0;
	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(m_window))
	{
		glClearColor(50.f / 255.f, 45.f / 255.f, 50.f / 255.f, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		double now = glfwGetTime();
		double delta = now - previous;
		previous = now;
		steps += delta;

		while (steps >= secsPerUpdate && steps >= 2 * secsPerUpdate) {
			Update((float)delta);
			steps -= secsPerUpdate;
		}

		Render();

		KeyListener::EndFrameImgui();
		MouseListener::EndFrameImgui();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

#include "scenes/Scene.h"
#include "scenes/ProjectileScene.h"
#include "scenes/RigidbodyScene.h"

int main()
{
	Scene* scene = new ProjectileScene();
	scene->Run();
	delete scene;

	return 0;
}
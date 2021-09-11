#include "Handler.hpp"


Handler::Handler(Layer& defaultScene):
	running(defaultScene),
	defaultScene(defaultScene.tags.front()),
	runningScene(defaultScene.tags.front())
{
	addEntity(&defaultScene);
}

int Handler::main()
{
	int status = running.update();
	if (status) 
	{
		int out = recieve(running,status);
		if (out) 
		{
			return out;
		}
	}
	return 0;
}

void Handler::switchScene(std::string& newScene, Layer* active)
{
	if (&getUniqueEntity(newScene) == active) {
		throw std::exception("added duplicate scene");
	}
	addEntity(active);
	createEntities();
	this->runningScene = newScene;
}


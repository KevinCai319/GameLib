#include "Handler.hpp"

Handler::Handler() :
	Layer(nullptr),
	running(nullptr),
	defaultScene(""), 
	runningScene("")
{}

Handler::Handler(Layer* parent, std::string& defaultScene) :
	Layer(parent), 
	running(nullptr),
	defaultScene(defaultScene), 
	runningScene(defaultScene)
{}

int Handler::main()
{
	if (running) 
	{
		int status = running->update();
		if (status) 
		{
			int out = recieve(*running,status);
			if (out) 
			{
				return out;
			}
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


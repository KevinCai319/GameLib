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
	// No draw call here, as this can't draw anyting.
	return 0;
}

void Handler::switchScene(std::string& newScene, Layer* active)
{
	// TODO: what if a layer pointer is added twice?
	addEntity(active);
	createEntities();
	this->runningScene = newScene;
}


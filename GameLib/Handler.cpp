#include "Handler.hpp"

Handler::Handler():Handler(nullptr,"default") 
{
}

Handler::Handler(Layer* parent, std::string default_scene):Layer(parent)
{
		this->default_scene = default_scene;
		this->running_scene = default_scene;
}

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
	addEntity(active);
	createEntities();
	this->running_scene = newScene;
}


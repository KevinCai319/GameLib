#include "Handler.hpp"

Handler::Handler():Handler(nullptr,"default") {
}

Handler::Handler(Layer* parent, std::string default_scene):Layer(parent)
{
		this->default_scene = default_scene;
		this->running_scene = default_scene;
}

int Handler::main()
{
	if (running_scene.empty()) {
		getUniqueEntity(running_scene).update();
	}
	// No draw call here, as this can't draw anyting.
	return 0;
}

void Handler::render(sf::RenderTarget& target, sf::RenderStates states) const
{
}


void Handler::recieve(int status)
{
}

void Handler::notify(Layer& layer, int status)
{
}

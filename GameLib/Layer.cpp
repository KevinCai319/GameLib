#include "Layer.hpp"

int Layer::update()
{
	return 0;
}

bool Layer::addEntity(sf::Drawable& layer)
{
	return false;
}

bool Layer::removeEntity(sf::Drawable& layer)
{
	return false;
}

bool Layer::modifyEntityTag(sf::Drawable& layer, std::string oldTag, std::string newTag)
{
	return false;
}

std::set<Layer>* Layer::getTag(std::string tag)
{
	return nullptr;
}

void Layer::recieve(int status)
{
}

void Layer::notify(Layer& layer, int status)
{
}

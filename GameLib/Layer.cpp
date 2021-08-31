#include "Layer.hpp"

int Layer::update(Layer* parent)
{
	//To be added stuff
	//To be destroyed stuff
	//update

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

std::set<sf::Drawable>* Layer::getTag(std::string tag)
{
	return &entities[tag];
}

void Layer::recieve(int status)
{
}

void Layer::notify(Layer& layer, int status)
{
}

#include "Layer.hpp"

Layer::Layer(Layer* parent)
{
	this->parent = parent;
	this->entities.clear();
	this->init();
}

int Layer::update()
{
	//To be added stuff
	//To be destroyed stuff
	//update
	
	
}
void Layer::createEntities() {
	while (!addEntityQueue.empty()) 
	{
		Layer* newEntity = &addEntityQueue.front();
		if (!newEntity->tags.empty()) 
		{
			std::vector<std::string> tagsToBeAdded = newEntity->tags;
			for (std::string tag : tagsToBeAdded) 
			{
				if (entities.count(tag) > 0) 
				{

				}
				else 
				{

				}
			}
			addEntityQueue.pop();
		}
	}
}

void Layer::destroyEntities() {
	while (!removeEntityQueue.empty())
	{
		Layer* garbageEntity = &removeEntityQueue.front();
		if (!garbageEntity->tags.empty())
		{
			std::vector<std::string> tagsToBeAdded = garbageEntity->tags;
			for (std::string tag : tagsToBeAdded)
			{
				if (entities.count(tag) > 0)
				{

				}
				else
				{
					std::cout << "Something really bad happened...\n";
				}
			}
			removeEntityQueue.pop();
		}
	}
}



bool Layer::addEntity(Layer& layer)
{
	this->addEntityQueue.push(layer);
	return true;
}

bool Layer::removeEntity(Layer& layer)
{
	this->removeEntityQueue.push(layer);
	return true;
}

bool Layer::modifyEntityTag(Layer& layer, std::string oldTag, std::string newTag)
{
	return false;
}

std::set<Layer>* Layer::getTag(std::string tag)
{
	return &entities[tag];
}

void Layer::init()
{
}

void Layer::recieve(int status)
{
}

void Layer::notify(Layer& layer, int status)
{
}

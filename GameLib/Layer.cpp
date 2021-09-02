#include "Layer.hpp"

Layer::Layer(Layer* parent)
{
	this->parent = parent;
	this->entities.clear();
	this->init();
}

void Layer::clean()
{
	//To be added stuff
	createEntities();
	//To be destroyed stuff
	destroyEntities();
}

int Layer::main()
{
	return 0;
}

int Layer::update()
{
	clean();
	//update everything else
	int out = main();
}

void Layer::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	
}

void Layer::drawChildren(sf::RenderTarget& target, sf::RenderStates states)
{
	for (std::vector<Layer> group : toUpdate) {
		group.draw(target, states);
	}
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
					entities[tag].insert(*newEntity);
				}
				else 
				{
					entities[tag] = std::set<Layer>();
					entities[tag].insert(*newEntity);
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
			std::vector<std::string> tagsToBeRemoved = garbageEntity->tags;
			for (std::string tag : tagsToBeRemoved)
			{
				if (entities.count(tag) > 0)
				{
					entities[tag].erase(*garbageEntity);
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

bool Layer::modifyEntityTag(Layer& layer, std::string& oldTag, std::string& newTag)
{
	return false;
}

std::set<Layer>& Layer::getTag(std::string& tag)
{
	return entities[tag]; 
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

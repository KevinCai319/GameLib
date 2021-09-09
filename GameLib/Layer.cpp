#include "Layer.hpp"

Layer::~Layer()
{
	for (Layer* child : toUpdate) {
		removeEntity(child);
	}
	destroyEntities();
}

Layer::Layer():Layer(nullptr)
{
}

Layer::Layer(Layer* parentLayer) 
{
	this->parent = parentLayer;
	this->entities.clear();
}

void Layer::clean()
{
	//To be added stuff
	createEntities();
	//To be destroyed stuff
	destroyEntities();
}
void Layer::linkParent(Layer* parent)
{
	this->parent = parent;
	screen = parent->getScreen();
}
sf::Window* Layer::getScreen()
{
	return screen;
}
int Layer::updateChildren() {
	for (Layer* group : toUpdate)
	{
		int signal = group->update();
		if (signal)
		{
			int out = recieve(*group, signal);
			if (out)
			{
				return out;
			}
		}
	}
	return 0;
}
int Layer::main()
{
	return updateChildren();
}

int Layer::update() 
{
	clean();
	//update everything else
	int out = main();
	return out;
}


void Layer::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	states.transform *= getTransform();
	for (Layer* group : toUpdate) {
		group->draw(target, states);
	}
	render(target,states);
}

void Layer::setScreen(sf::Window& screen)
{
	this->screen = &screen;
}


void Layer::createEntities(){
	while (!addEntityQueue.empty()) 
	{
		Layer* newEntity = addEntityQueue.front();
		newEntity->linkParent(this);
		if (!newEntity->tags.empty()) 
		{
			std::vector<std::string> tagsToBeAdded = newEntity->tags;
			for (std::string tag : tagsToBeAdded) 
			{
				entities[tag].insert(newEntity);
			}
		}
		toUpdate.insert(newEntity);
		addEntityQueue.pop();
	}
}

void Layer::destroyEntities() {
	while (!removeEntityQueue.empty())
	{
		Layer* garbageEntity = removeEntityQueue.front();
		if (garbageEntity && !garbageEntity->tags.empty())
		{
			toUpdate.erase(garbageEntity);
			std::vector<std::string> tagsToBeRemoved = garbageEntity->tags;
			for (std::string tag : tagsToBeRemoved)
			{
				if (entities.count(tag) > 0)
				{
					entities[tag].erase(garbageEntity);
				}
				else
				{
					std::cout << "Something really bad happened...\n";
				}
			}
			delete garbageEntity;
			removeEntityQueue.pop();
		}
	}
}

bool Layer::addEntity(Layer* layer)
{
	this->addEntityQueue.push(layer);
	return true;
}

bool Layer::removeEntity(Layer* layer)
{
	this->removeEntityQueue.push(layer);
	return true;
}

const std::set<Layer*>& Layer::getTag(std::string& tag)
{
	return entities[tag];
}

bool Layer::modifyEntityTag(Layer* layer, std::string& oldTag, std::string& newTag)
{
	return false;
}

Layer& Layer::getUniqueEntity(std::string& tag)
{
	if (entities[tag].size() != 1) {
		std::cout << "Asked for unique object of tag:" << tag << ", but found" << entities[tag].size() << "items.";
		throw std::exception();
	}
	return const_cast<Layer&> (**(entities[tag].begin()));

}


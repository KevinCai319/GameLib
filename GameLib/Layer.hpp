#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <queue>
#include <set>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


#define LAYER_BACK 0;
#define LAYER_MID 1;
#define LAYER_FRONT 2;
// Some notes about the layer class and traversing upwards/downwards:
// - Ideally, there shouldn't be any kind of traversal upwards and then downards.
//		- It is possible to do so, but it isn't a clean solution and should be avoided.
// - 2 entity updates might interfere with each other. This should be handled between the two entities.
class Layer : public sf::Drawable, public sf::Transformable
{
public:
	//List of all tags that this layer contains.
	std::vector<std::string> tags;
	int renderPriority = LAYER_BACK;

	//constructor/destructor
	Layer();
	~Layer();

	//initalization functions(parent, window)
	void linkParent(Layer* parent);
	sf::Window* getScreen();
	void setScreen(sf::Window* screen);

	//loop control functions
	void refresh();
	virtual int update();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Add/Remove functions
	bool addEntity(Layer* layer);
	bool removeEntity(Layer* layer);
	bool updateIndex(std::string str, int i);
	//tag functions
	const std::vector<Layer*>& getTag(const std::string& tag);
	Layer& getUniqueEntity(const std::string& tag);
	bool modifyEntityTag(Layer* layer, const std::string& oldTag, const std::string& newTag);
protected:
	//Collections of objects.
	std::unordered_map<std::string, std::vector<Layer*>> entities;
	std::unordered_map<std::string, int> positions;
	std::vector<Layer*> toUpdate;
	std::queue<std::vector<Layer*>> toRender;
	std::queue<Layer*> addEntityQueue;
	std::queue<Layer*> removeEntityQueue;

	Layer* parent = nullptr;
	sf::Window* screen = nullptr;

	//optional status variable which can be used by implementations.
	int status = 0;
	int updateChildren();
	void killAll();
	void killChildren();
	void createEntities();
	void destroyEntities();
	virtual int main();
	virtual void render(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual int recieve(Layer& layer, int status);
	virtual void notify(Layer& layer, int status);

};


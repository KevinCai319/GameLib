#pragma once

#include <map>

#include <set>
#include <string>
#include <queue>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Layer : public sf::Drawable, public sf::Transformable 
{
	public:
		int update();
		bool addEntity(sf::Drawable& layer);
		bool removeEntity(sf::Drawable& layer);
		

	private:
		std::map<std::string, std::set<sf::Drawable>> entities;
		std::queue<sf::Drawable> addEntityQueue;
		std::queue<sf::Drawable> removeEntityQueue;
		Layer* parent;
};


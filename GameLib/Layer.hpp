#pragma once

#include <string>
#include <map>
#include <set>
#include <queue>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


// Some notes about the layer class and traversing upwards/downwards:
// - Ideally, there shouldn't be any kind of traversal upwards and then downards.
//		- It is possible to do so, but it isn't a clean solution and should be avoided.
// - 2 entity updates might interfere with each other. This should be handled between the two entities.
class Layer : public sf::Drawable, public sf::Transformable 
{
	
	public:
		//used by a layer to skip an update call or not.
		bool skipUpdate;
		
		////////////////////////////////////////////////////////////
		/// \brief Update every entity contained in this layer.
		/// \param parent: the parent of this layer.
		////////////////////////////////////////////////////////////
		int update(Layer* parent);

		
		////////////////////////////////////////////////////////////
		/// \brief Add an entity to this layer.
		/// \param layer: the entity to add.
		////////////////////////////////////////////////////////////
		bool addEntity(sf::Drawable& layer);

		
		////////////////////////////////////////////////////////////
		/// \brief Remove an entity from this layer.
		/// \param layer: the entity to remove.
		////////////////////////////////////////////////////////////
		bool removeEntity(sf::Drawable& layer);
		
		
		////////////////////////////////////////////////////////////
		/// \brief Modify an entity's tag. Can be used to add/remove/replace a tag from an entity. 
		/// \param layer: the layer to edit.
		/// \param oldTag: the old tag to be removed. If null, then no tag from layer is removed. 
		/// \param newTag: the new tag to be added. If null, then no new tag is given.
		////////////////////////////////////////////////////////////
		bool modifyEntityTag(sf::Drawable& layer, std::string oldTag, std::string newTag);

		////////////////////////////////////////////////////////////
		/// \brief Recieve all tags with a given tag within this layer.
		/// \param tag: the tag of the entities to be returned.
		////////////////////////////////////////////////////////////
		std::set<sf::Drawable>* getTag(std::string tag);
		
		// handle request
		virtual void recieve(int status);
		
		// send request
		virtual void notify(Layer& layer,int status);

	private:
		std::map<std::string, std::set<sf::Drawable>> entities;
		std::queue<sf::Drawable> addEntityQueue;
		std::queue<sf::Drawable> removeEntityQueue;
		Layer* parent;
};


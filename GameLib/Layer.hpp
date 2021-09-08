#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
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
		bool skipUpdate = false;
		int status = 0;
		std::vector<std::string> tags;
		~Layer();
		Layer();
		////////////////////////////////////////////////////////////
		/// \brief Create a new layer.
		/// \param parent: the parent of this layer.
		////////////////////////////////////////////////////////////
		Layer(Layer* parentLayer);
		
		////////////////////////////////////////////////////////////
		/// \brief handle important operations between frames.(add/delete/modify objects)
		/// 
		////////////////////////////////////////////////////////////
		void clean();
		void linkParent(Layer* parent);
		sf::Window* getScreen();
		//can be called by extending classes if needed.
		int updateChildren();
		
		////////////////////////////////////////////////////////////
		/// \brief Update every entity contained in this layer.
		/// \param parent: the parent of this layer.
		////////////////////////////////////////////////////////////
		int update();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override ;
		void setScreen(sf::Window& screen);
		////////////////////////////////////////////////////////////
		/// \brief Add an entity to this layer.
		/// \param layer: the entity to add.
		////////////////////////////////////////////////////////////
		bool addEntity(Layer* layer);

		
		////////////////////////////////////////////////////////////
		/// \brief Remove an entity from this layer.
		/// \param layer: the entity to remove.
		////////////////////////////////////////////////////////////
		bool removeEntity(Layer* layer);
		
		////////////////////////////////////////////////////////////
		/// \brief Recieve all tags with a given tag within this layer.
		/// \param tag: the tag of the entities to be returned.
		////////////////////////////////////////////////////////////
		const std::set<Layer*>& getTag(std::string& tag);

		////////////////////////////////////////////////////////////
		/// \brief Modify an entity's tag. Can be used to add/remove/replace a tag from an entity. 
		/// \param layer: the layer to edit.
		/// \param oldTag: the old tag to be removed. If null, then no tag from layer is removed. 
		/// \param newTag: the new tag to be added. If null, then no new tag is given.
		////////////////////////////////////////////////////////////
		bool modifyEntityTag(Layer* layer, std::string& oldTag, std::string& newTag);


		Layer& getUniqueEntity(std::string& tag);
		
		virtual int main() = 0;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const = 0;
		virtual int recieve(Layer& layer, int status) = 0;
		virtual void notify(Layer& layer,int status) = 0;
		
	protected:
		std::unordered_map<std::string, std::set<Layer*>> entities;
		std::set<Layer*> toUpdate;
		std::queue<Layer*> addEntityQueue;
		std::queue<Layer*> removeEntityQueue;
		Layer* parent = nullptr;
		sf::Window* screen = nullptr;
		void createEntities();
		void destroyEntities();
};


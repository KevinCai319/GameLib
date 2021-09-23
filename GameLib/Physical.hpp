#pragma once
#include "Layer.hpp"
#include <SFML/Graphics.hpp>
class Physical:public Layer
{
	public:
		Physical();
		virtual const sf::Shape& getShape() = 0;
		virtual const sf::FloatRect& getAABB();
		float dotProduct(sf::Vector2f p0, sf::Vector2f p1);
		std::vector<sf::Vector2f> getAxis(const sf::Shape& shape);
		virtual const bool isColliding(Physical& other) const = 0;
		static bool isABBBColling(sf::FloatRect a, sf::FloatRect b);
	protected:

};


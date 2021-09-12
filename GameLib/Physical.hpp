#pragma once
#include <SFML\Graphics.hpp>
class Physical
{
	public:
		virtual const sf::Shape& getShape() = 0;
		float dotProduct(sf::Vector2f p0, sf::Vector2f p1);
		std::vector<sf::Vector2f> getAxis(const sf::Shape& shape);
		virtual const bool isColliding(Physical& other);
	protected:

};


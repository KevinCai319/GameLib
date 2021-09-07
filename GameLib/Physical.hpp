#pragma once
#include <SFML\Graphics.hpp>
class Physical
{
	public:
		virtual const sf::Shape& getShape() = 0;
		virtual const bool isColliding(Physical& other);
	protected:

};


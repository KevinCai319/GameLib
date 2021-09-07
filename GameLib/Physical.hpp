#pragma once
#include <SFML\Graphics.hpp>
class Physical
{
	public:
		virtual const sf::VertexArray getShape()const = 0;
		virtual const bool isColliding()const = 0;
	private:
};


#include "Ball.hpp"

Ball::Ball()
{
}

int Ball::main()
{
	box.move(velocity);
	std::set<Layer*> solids = parent->getTag("Physical");
	return status;
}

void Ball::render(sf::RenderTarget& target, sf::RenderStates states) const
{
}

const sf::Shape& Ball::getShape()
{
	return box;
}

const sf::FloatRect Ball::getAABB()
{
	return box.getLocalBounds();
}

void Ball::notify(Layer& layer, int status)
{
	this->status = status;
}

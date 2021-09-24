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
	// TODO: insert return statement here
}

const sf::FloatRect& Ball::getAABB()
{
	// TODO: insert return statement here
}

void Ball::notify(Layer& layer, int status)
{
	this->status = status;
}

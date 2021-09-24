#include "Paddle.hpp"

Paddle::Paddle(float x, float y, int yMin, int yMax, sf::Keyboard::Key up, sf::Keyboard::Key down) :
	Physical::Physical(), 
	Timed::Timed(),
	yMin(yMin),
	yMax(yMax),
	up(up),
	down(down),
	box(sf::RectangleShape(sf::Vector2f(20.0f, (yMax - yMin) / 4.0f)))
{
	Layer::tags.push_back("Paddle");
	box.setPosition(x,y);
	box.setOutlineColor(sf::Color::Red);
	box.setOutlineThickness(20);
}

int Paddle::main(sf::Time dt) {
	if (sf::Keyboard::isKeyPressed(up))
	{
		box.move(sf::Vector2f(0, -velocity * dt.asSeconds()));
	}
	if (sf::Keyboard::isKeyPressed(down))
	{
		box.move(sf::Vector2f(0, velocity * dt.asSeconds()));
	}
	return 0;
}

void Paddle::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(box, states);
}

const sf::Shape& Paddle::getShape()
{
	return box;
}
const sf::FloatRect Paddle::getAABB()
{
	return box.getLocalBounds();
}
int Paddle::recieve(Layer& layer, int status)
{
	return 0;
}

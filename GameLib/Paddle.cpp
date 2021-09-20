#include "Paddle.hpp"

Paddle::Paddle(int x, int y, int yMin, int yMax, sf::Keyboard::Key up, sf::Keyboard::Key down) :
	yMin(yMin),
	yMax(yMax),
	box(sf::RectangleShape(sf::Vector2f(20, (yMax - yMin) / 4))),
	velocity(10),
	up(up),
	down(down)
{
	tags.push_back("Paddle");
	box.setPosition(x,y);
	box.setOutlineColor(sf::Color::Red);
	box.setOutlineThickness(20);
}

int Paddle::main() {
	Layer::main();
	if (sf::Keyboard::isKeyPressed(up))
	{
		box.move(sf::Vector2f(0, -velocity));
	}
	if (sf::Keyboard::isKeyPressed(down))
	{
		box.move(sf::Vector2f(0, velocity));
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
const sf::FloatRect& Paddle::getAABB()
{
	return box.getGlobalBounds();
}
int Paddle::recieve(Layer& layer, int status)
{
	return 0;
}



#include "Button.hpp"
Button::Button():Button(sf::RectangleShape(sf::Vector2f(200.0f, 200.0f)))
{
}
Button::Button(sf::RectangleShape hitbox) :
	isClicked(false),
	isHovering(false),
	onActivated(nullptr),
	onHover(nullptr),
	hitbox(hitbox)
{
}

Button::~Button()
{
}

const sf::Shape& Button::getShape()
{
	return hitbox;
}

int Button::main()
{
	return 0;
}

void Button::render(sf::RenderTarget& target, sf::RenderStates states) const
{
}

int Button::recieve(Layer& layer, int status)
{
	return 0;
}

void Button::notify(Layer& layer, int status)
{
}

bool Button::checkHover()
{
	sf::Vector2i cursor = sf::Mouse::getPosition();
	std::cout << cursor.x<<","<<cursor.y << std::endl;
	std::cout << "mouse position\n";
	return false;
}



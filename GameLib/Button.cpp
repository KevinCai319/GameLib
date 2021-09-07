#include "Button.hpp"
Button::Button():Button(sf::RectangleShape(sf::Vector2f(200.0f, 200.0f)))
{
}
Button::Button(int x, int y, int w, int h)
{
	hitbox = sf::RectangleShape(sf::Vector2f(x, y));
	hitbox.setSize(sf::Vector2f(w,h));
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(5);
	isClicked = false;
	isHovering = false;
	onClick = nullptr,
	onHover = nullptr;
}
Button::Button(sf::RectangleShape hitbox) :
	isClicked(false),
	isHovering(false),
	onClick({}),
	onHover({}),
	hitbox(hitbox)
{
}

Button::~Button()
{
}

void Button::setClickFunction(void(*function)())
{
	onClick = function;
}

void Button::setHoverFunction(void(*function)())
{
	onHover = function;
}

const sf::Shape& Button::getShape()
{
	return hitbox;
}

int Button::main()
{
	isHovering = checkHover();
	if (isHovering) {
		onHover();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			onClick();
		}
	}
	
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



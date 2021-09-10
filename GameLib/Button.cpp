#include "Button.hpp"
Button::Button():Button(sf::RectangleShape(sf::Vector2f(200.0f, 200.0f)))
{
	tags.push_back("Physical");
	tags.push_back("Button");
}
Button::Button(float x, float y, float w, float h):
	isMouseDown(false),
	isHovering(false),
	onClick(nullptr),
	onHover(nullptr)
{
	hitbox = sf::RectangleShape(sf::Vector2f(w,h));
	hitbox.setPosition(sf::Vector2f(x,y));
	hitbox.setOutlineColor(sf::Color::Red);
	hitbox.setOutlineThickness(5);
	tags.push_back("Physical");
	tags.push_back("Button");
}
Button::Button(sf::RectangleShape hitbox) :
	isMouseDown(false),
	isHovering(false),
	onClick(nullptr),
	onHover(nullptr),
	hitbox(hitbox)
{
	tags.push_back("Physical");
	tags.push_back("Button");
}



void Button::setClickFunction(void(*function)())
{
	if(function)onClick = function;
}


//TODO: Look at std::function or templates
void Button::setHoverFunction(void(*function)())
{
	if (function)onHover = function;
}

const sf::Shape& Button::getShape()
{
	return hitbox;
}


int Button::main()
{
	if (checkHover()) {
		hitbox.setOutlineColor(sf::Color::Red);
		if(onHover != nullptr)onHover();
		if (checkClick()) {
			if(onClick != nullptr)onClick();
		}
	} else {
		hitbox.setOutlineColor(sf::Color::Green);
	}
	return 0;
}

void Button::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hitbox, states);
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
	return isHovering = hitbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*screen).x, sf::Mouse::getPosition(*screen).y));
}
bool Button::checkClick()
{
	return isMouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}



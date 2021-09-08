#include "Button.hpp"
Button::Button():Button(sf::RectangleShape(sf::Vector2f(200.0f, 200.0f)))
{
	tags.push_back("Physical");
	tags.push_back("Button");
}
Button::Button(float x, float y, float w, float h):
	isClicked(false),
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
	isClicked(false),
	isHovering(false),
	onClick(nullptr),
	onHover(nullptr),
	hitbox(hitbox)
{
	tags.push_back("Physical");
	tags.push_back("Button");
}

Button::~Button()
{
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
		if(onHover)onHover();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if(onClick)onClick();
		}
	} else {

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
	return hitbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*screen).x, sf::Mouse::getPosition(*screen).y));
}



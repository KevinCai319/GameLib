#include "Button.hpp"

Button::Button(const sf::RectangleShape& hitbox, const sf::Text& text) :
	hitbox(hitbox), 
	text(text)
{
	alignTextCenter(); 
	tags.push_back("Physical");
	tags.push_back("Button");
}

Button::Button(const sf::RectangleShape& hitbox) : 
	hitbox(hitbox) 
{
	tags.push_back("Physical"); 
	tags.push_back("Button"); 
}

Button::Button(float x, float y, float w, float h) : 
	hitbox(sf::Vector2f(w, h))
{
	hitbox.setPosition(sf::Vector2f(x, y)); 
	hitbox.setOutlineColor(sf::Color::Red); 
	hitbox.setOutlineThickness(20); 
	tags.push_back("Physical"); 
	tags.push_back("Button"); 
}

Button::Button() :
	hitbox(sf::Vector2f(200.f, 200.f))
{
	hitbox.setPosition(0.f, 0.f); 
	tags.push_back("Physical"); 
	tags.push_back("Button"); 
}

void Button::setClickFunction(std::function<void()> function)
{
	if(function)onClick = function;
}

void Button::setHoverFunction(std::function<void()> function)
{
	if (function)onHover = function;
}

void Button::setText(const sf::Text& text)
{
	this->text = text; 
	alignTextCenter(); 
}

const sf::Shape& Button::getShape()
{
	return hitbox;
}

const sf::Text& Button::getText()
{
	return text; 
}

void Button::alignTextLeft()
{
	float hbheight = hitbox.getGlobalBounds().height - 2 * hitbox.getOutlineThickness(); 
	float offsetx = 0; 
	float offsety = (hbheight - text.getGlobalBounds().height) / 2; 
	float gap = text.getCharacterSize() - text.getGlobalBounds().height; 
	text.setPosition(sf::Vector2f(hitbox.getPosition().x + offsetx, hitbox.getPosition().y + offsety - gap)); 
}

void Button::alignTextCenter()
{
	float hbwidth = hitbox.getGlobalBounds().width - 2 * hitbox.getOutlineThickness(); 
	float hbheight = hitbox.getGlobalBounds().height - 2 * hitbox.getOutlineThickness(); 
	float offsetx = (hbwidth - text.getGlobalBounds().width) / 2;
	float offsety = (hbheight - text.getGlobalBounds().height) / 2; 
	float gap = text.getCharacterSize() - text.getGlobalBounds().height; 
	text.setPosition(sf::Vector2f(hitbox.getPosition().x + offsetx, hitbox.getPosition().y + offsety - gap)); 
}

void Button::alignTextRight()
{
	float hbwidth = hitbox.getGlobalBounds().width - 2 * hitbox.getOutlineThickness(); 
	float hbheight = hitbox.getGlobalBounds().height - 2 * hitbox.getOutlineThickness(); 
	float offsetx = (hbwidth - text.getGlobalBounds().width);
	float offsety = (hbheight - text.getGlobalBounds().height) / 2; 
	float gap = text.getCharacterSize() - text.getGlobalBounds().height; 
	text.setPosition(sf::Vector2f(hitbox.getPosition().x + offsetx, hitbox.getPosition().y + offsety - gap)); 
}

int Button::main()
{
	status = 0;
	if (checkHover()) 
	{
		hitbox.setOutlineColor(sf::Color::Red);
		if(onHover != nullptr)onHover();
		if (checkClick()) 
		{
			if(onClick != nullptr)onClick();
		}
	} 
	else 
	{
		hitbox.setOutlineColor(sf::Color::Green);
	}
	return status;
}

void Button::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(hitbox, states);
	target.draw(text, states); 
}


int Button::recieve(Layer& layer, int status)
{
	return 0;
}

void Button::notify(Layer& layer, int status)
{
	this->status = status;
}

bool Button::checkHover()
{
	sf::Vector2i pos = sf::Mouse::getPosition(*screen);
	float px = 0.0f + pos.x;
	float py = 0.0f + pos.y;
	return isHovering = hitbox.getGlobalBounds().contains(sf::Vector2f(px,py));
}
bool Button::checkClick()
{
	return isMouseDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}



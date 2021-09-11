#pragma once
#include "Physical.hpp"
#include "Layer.hpp"
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Window\Cursor.hpp>
class Button:public Physical,public Layer
{
	public:
		Button();
		Button(sf::RectangleShape hitbox);
		Button(float x, float y, float w, float h);
		void setClickFunction(std::function<void()> function);
		void setHoverFunction(std::function<void()> function);
		const sf::Shape& getShape()override;
		virtual int main() override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;

		// handle request
		virtual int recieve(Layer& layer, int status) override;

		// send request
		virtual void notify(Layer& layer, int status) override;
		bool checkHover();
		bool checkClick();
	private:
		sf::RectangleShape hitbox;
		sf::Text text;
		sf::Image image;
		bool isHovering;
		bool isMouseDown;
		std::function<void()> onClick;
		std::function<void()> onHover;
};


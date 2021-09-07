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
		~Button();
		const sf::Shape& getShape()override;
		virtual int main() override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;

		// handle request
		virtual int recieve(Layer& layer, int status) override;

		// send request
		virtual void notify(Layer& layer, int status) override;
		bool checkHover();
	private:
		sf::RectangleShape hitbox;
		bool isHovering;
		bool isClicked;
		void(*onActivated);
		void(*onHover);
};


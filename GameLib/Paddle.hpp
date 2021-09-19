#pragma once
#include "Layer.hpp"
#include "Physical.hpp"
class Paddle :public Layer, public Physical
{
	public:
		Paddle(int x, int y,int yMin,int yMax, sf::Keyboard::Key up, sf::Keyboard::Key down);
		virtual int main()override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual const sf::Shape& getShape() override;
		virtual const sf::FloatRect& getAABB() override;
		int velocity;
	protected:
		sf::RectangleShape box;
		int yMin, yMax;
		sf::Keyboard::Key up, down;
		virtual int recieve(Layer& layer, int status) override;
};

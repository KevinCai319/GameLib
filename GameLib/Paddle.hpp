#pragma once
#include "Layer.hpp"
#include "Physical.hpp"
#include "Timed.hpp"
class Paddle : public Physical, public Timed
{
	public:
		Paddle(int x, int y,int yMin,int yMax, sf::Keyboard::Key up, sf::Keyboard::Key down);
		virtual int main(sf::Time dt) override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual const sf::Shape& getShape() override;
		virtual const sf::FloatRect& getAABB() override;
		int velocity = 1;
	protected:
		int yMin, yMax;
		sf::Keyboard::Key up, down;
		sf::RectangleShape box;
		virtual int recieve(Layer& layer, int status) override;
};

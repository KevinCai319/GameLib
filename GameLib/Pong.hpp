#pragma once
#include "TimedLayer.hpp"
#include "Paddle.hpp"
class Pong : public TimedLayer
{
	public:
		Pong();
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
	private:
		int p1score = 0;
		int p2score = 0;
		sf::Text* p1Display = nullptr;
		sf::Text* p2Display = nullptr;
};


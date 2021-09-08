#pragma once
#include "layer.hpp"
class MainMenu : public Layer
{
	public:
		MainMenu();
		virtual int main()override;
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};


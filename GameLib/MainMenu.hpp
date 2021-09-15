#pragma once
#include "Layer.hpp"
class MainMenu : public Layer
{
	public:
		MainMenu();
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		virtual int recieve(Layer& layer, int status)override;
		virtual void notify(Layer& layer, int status)override;
};


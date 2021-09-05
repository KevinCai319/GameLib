#pragma once
#include "Handler.hpp"
class WindowHandler:public Handler
{
	public:
		WindowHandler(int x, int y,std::string title);
		void render();
		virtual void render(sf::RenderTarget& target, sf::RenderStates states)const override;
		int main() override;
		// handle request
		virtual int recieve(Layer& layer,int status)override;
		
		// send request
		virtual void notify(Layer& layer, int status)override;
	private:
		sf::RenderWindow* window;
		
};


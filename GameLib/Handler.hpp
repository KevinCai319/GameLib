#pragma once

#include "Layer.hpp"
class Handler : public Layer{
	public:
		Handler();
		Handler(Layer* parent,std::string default_scene);
		int main() override;
		void render(sf::RenderTarget& target, sf::RenderStates states) const override;

		// handle request
		void recieve(int status)override;

		// send request
		void notify(Layer& layer, int status)override;

	private:
		std::string running_scene;
		std::string default_scene;
};


#pragma once

#include "Layer.hpp"
class Handler : public Layer{
	public:
		Handler(Layer* defaultScene);
		~Handler();
		int main() override;
		virtual void switchScene(Layer* active);
	protected:
		std::string runningScene;
		std::string defaultScene;
		Layer* running;
};


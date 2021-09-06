#pragma once

#include "Layer.hpp"
class Handler : public Layer{
	public:
		Handler();
		Handler(Layer* parent,std::string& default_scene);
		int main() override;
		virtual void switchScene(std::string& newScene, Layer* active);
	protected:
		std::string runningScene;
		std::string defaultScene;
		Layer* running;
};


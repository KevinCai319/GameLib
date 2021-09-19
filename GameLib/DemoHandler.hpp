#pragma once
#include "WindowHandler.hpp"
#include "MainMenu.hpp"
#include "Pong.hpp"
class DemoHandler : public WindowHandler
{
	public:
		DemoHandler(int x, int y, const std::string& title,Layer* menu);
		virtual int recieve(Layer& layer, int status) override;
};


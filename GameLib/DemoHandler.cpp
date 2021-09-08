#include "DemoHandler.hpp"
DemoHandler::DemoHandler(int x, int y, const std::string& title):WindowHandler(x,y,title)
{
	tags.push_back("Root");
	MainMenu* menuScene = new MainMenu();
	defaultScene = "Menu";
	runningScene = "Menu";
	running = menuScene;
	addEntity(menuScene);
}

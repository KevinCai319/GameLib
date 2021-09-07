#include "MainMenu.hpp"
#include "Button.hpp"

MainMenu::MainMenu(int x, int y, const std::string& title):WindowHandler(x,y,title)
{
	tags.push_back("Menu");
	addEntity(new Button(400,400,50,10));
}

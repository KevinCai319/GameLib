#include "MainMenu.hpp"
#include "Button.hpp"
MainMenu::MainMenu()
{
	tags.push_back("Menu");
	
	addEntity(new Button(400,400,100,100));
}

int MainMenu::main()
{
	int result = updateChildren();
	if(result)return result;
	return 0;
}

void MainMenu::render(sf::RenderTarget& target, sf::RenderStates states) const
{
}

int MainMenu::recieve(Layer& layer, int status)
{
	return 0;
}

void MainMenu::notify(Layer& layer, int status)
{
}

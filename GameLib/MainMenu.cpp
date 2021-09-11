#include "MainMenu.hpp"
#include "Button.hpp"
MainMenu::MainMenu()
{
	tags.push_back("Menu");
	Button* playButton = new Button(200, 200, 400, 100);
	Button* instructionsButton = new Button(200, 400, 400, 100);
	Button* exitButton = new Button(200, 600, 400, 100);
	exitButton->setClickFunction([this,exitButton]()
		{
			exitButton->notify(*this, -1);
		});
	instructionsButton->setClickFunction([this, instructionsButton]()
		{
			instructionsButton->notify(*this, 1);
		});
	addEntity(playButton);
	addEntity(instructionsButton);
	addEntity(exitButton);
}


void MainMenu::render(sf::RenderTarget& target, sf::RenderStates states) const
{
}

int MainMenu::recieve(Layer& layer, int status)
{
	if (status == -1) {
		std::cout << "working" << std::endl;
		return status;
	}
	return status;
}

void MainMenu::notify(Layer& layer, int status)
{
}

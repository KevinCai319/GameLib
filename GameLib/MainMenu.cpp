#include "MainMenu.hpp"
#include "Button.hpp"
MainMenu::MainMenu()
{
	tags.insert("Menu");
	sf::Font* ft = new sf::Font();
	if (!ft->loadFromFile("Assets\\Roboto-Regular.ttf"))
	{
		std::cout << "Something went wrong" << std::endl; 
		return; 
	}
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
	playButton->setClickFunction([this, playButton]()
		{
			playButton->notify(*this, 2);
		});

	sf::Text text1 ("Play Game", *ft); 
	text1.setFillColor(sf::Color::Blue); 
	text1.setCharacterSize(36); 
	playButton->setText(text1); 
	playButton->alignTextCenter(); 

	sf::Text text2 ("Instructions", *ft);
	text2.setFillColor(sf::Color::Blue); 
	text2.setCharacterSize(36); 
	instructionsButton->setText(text2); 
	instructionsButton->alignTextCenter(); 

	sf::Text text3 ("Exit", *ft);
	text3.setFillColor(sf::Color::Blue); 
	text3.setCharacterSize(36); 
	exitButton->setText(text3); 
	exitButton->alignTextCenter(); 

	addEntity(playButton);
	addEntity(instructionsButton);
	addEntity(exitButton);

	// TODO: MAJOR MEMORY LEAK - free the font
}


int MainMenu::recieve(Layer& layer, int status)
{
	if (status == -1) {
		return status;
	}		
	return status;
}

void MainMenu::notify(Layer& layer, int status)
{
}

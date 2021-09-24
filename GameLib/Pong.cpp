#include "Pong.hpp"

Pong::Pong(){
	tags.insert("Game");
	sf::Font* scoreFont = new sf::Font();
	if (!scoreFont->loadFromFile("Assets\\Roboto-Regular.ttf"))
	{
		std::cout << "Something went wrong" << std::endl;
		return;
	}
	p1Display = new sf::Text("0", *scoreFont);
	p2Display = new sf::Text("0", *scoreFont);
	p1Display->setPosition(1920/2 +40, 40);
	p2Display->setPosition(1920/2-40, 40);
	p1Display->setFillColor(sf::Color::White);
	p2Display->setFillColor(sf::Color::White);
	Paddle* Lpaddle = new Paddle(1920/8,1080/2,1080/8,1080*7/8,sf::Keyboard::W, sf::Keyboard::S);
	Paddle* Rpaddle = new Paddle(1920*7/ 8, 1080 / 2, 1080 / 8, 1080 * 7 / 8, sf::Keyboard::I, sf::Keyboard::K);
	addEntity(Lpaddle);
	addEntity(Rpaddle);
}

void Pong::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*p1Display,states);
	target.draw(*p2Display, states);
}

int Pong::recieve(Layer& layer, int status)
{

	if(status == 1){// scores
		p1score++;
	}
	else if (status == 2) {// scores
		p2score++;
	}
	else if (status == -1) {//error/exit
		return -1;
	}
	return 0;
}

void Pong::notify(Layer& layer, int status)
{
}

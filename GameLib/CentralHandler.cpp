#include "CentralHandler.hpp"

//Setup main window and graphics reference.
CentralHandler::CentralHandler() :Handler()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Test program");
}

void CentralHandler::render()
{
	window->clear();
	render(*window, sf::RenderStates::Default);
	window->display();
}
void CentralHandler::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	running->render(target, states);
}

int CentralHandler::main()
{
	int res = Handler::main();
	if (res)return res;
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed) {
			window->close();
			return 1;
		}
	}
}

int CentralHandler::recieve(Layer& layer, int status)
{
	return 0;
}

//not used.
void CentralHandler::notify(Layer& layer, int status)
{
}

#include "WindowHandler.hpp"

//Setup main window and graphics reference.
WindowHandler::WindowHandler(int x, int y, std::string title) :Handler()
{
	window = new sf::RenderWindow(sf::VideoMode(x,y), title);
	tags.push_back("Window");
}

void WindowHandler::render()
{
	window->clear();
	if (running) {
		render(*window, sf::RenderStates::Default);
	}
	window->display();
}
void WindowHandler::render(sf::RenderTarget& target, sf::RenderStates states) const
{
	running->render(target, states);
}

int WindowHandler::main()
{
	int res = Handler::main();
	if (res)return res;
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Close window: exit
		if (event.type == sf::Event::Closed) {
			window->close();
			delete window;
			return 1;
		}
	}
}

int WindowHandler::recieve(Layer& layer, int status)
{
	return 0;
}

//not used.
void WindowHandler::notify(Layer& layer, int status)
{
}
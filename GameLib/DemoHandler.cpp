#include "DemoHandler.hpp"
DemoHandler::DemoHandler(int x, int y, const std::string& title,Layer* menu):WindowHandler(x,y,title,menu)
{
	tags.push_back("Root");
}

int DemoHandler::recieve(Layer& layer, int status)
{
	if (status < 0) {
		std::cout << "Exit" << std::endl;
		return status;//Error or exit state
	}
	if (status == 1){//Instructions
		std::cout << "go to instructions screen(WIP)" << std::endl;
	}
	if (status == 2) {//PONG
		switchScene(new Pong);
	}
	if (status == 3) {
		switchScene(&getUniqueEntity("menu"));
	}
	return 0;
}

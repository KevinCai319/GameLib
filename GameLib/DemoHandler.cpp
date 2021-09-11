#include "DemoHandler.hpp"
DemoHandler::DemoHandler(int x, int y, const std::string& title,Layer& menu):WindowHandler(x,y,title,menu)
{
	tags.push_back("Root");
}

int DemoHandler::recieve(Layer& layer, int status)
{
	if (status <0)return status;//Error or exit state
	if (status == 1){
		std::cout << "go to instructions screen(WIP)" << std::endl;
	}
	return 0;
}
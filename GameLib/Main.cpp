#include "DemoHandler.hpp"
#include "MainMenu.hpp"
#include <time.h> // header file for clock() function
#include <stdio.h> // header file for printf()
int main() {
	DemoHandler* main = new DemoHandler(1920, 1080, "Pong", new MainMenu());

	while (main->update() == 0) {
		main->render();
	}
	delete main;
	
	std::cout << "Exited successfully!" << std::endl;
	return 0;
}
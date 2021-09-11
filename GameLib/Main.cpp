#include "DemoHandler.hpp"
#include "MainMenu.hpp"
int main() {
	MainMenu mainMenu;
	DemoHandler main(1920, 1080, "Pong",mainMenu);
	while (main.update() == 0) {
		main.render();
	}
	return 0;
}
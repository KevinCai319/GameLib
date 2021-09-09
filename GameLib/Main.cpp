#include "DemoHandler.hpp"
int main() {
	DemoHandler* main = new DemoHandler(1920, 1080, "Pong");
	
	while (main->update() == 0) {
		main->render();
	}
	delete main;
	return 0;
}
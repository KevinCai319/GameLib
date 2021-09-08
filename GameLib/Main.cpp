#include "DemoHandler.hpp"
int main() {
	DemoHandler main(1920, 1080, "Pong");
	
	while (main.update() == 0) {
		main.render();
	}
	return 0;
}
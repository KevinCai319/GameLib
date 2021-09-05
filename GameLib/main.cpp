#include "WindowHandler.hpp"
int main() {
	WindowHandler main(1920,1080,"Demo");
	while (main.update() == 0) {
		main.render();
	}
	return 0;
}
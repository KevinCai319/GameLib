#include "WindowHandler.hpp"
int main() {
	std::string tmp = "Demo";
	WindowHandler main(1920, 1080, tmp);
	while (main.update() == 0) {
		main.render();
	}
	return 0;
}
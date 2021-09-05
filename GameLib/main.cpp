#include "CentralHandler.hpp"
int main() {
	CentralHandler main;
	while (main.update() == 0) {
		//main.render();
	}
	return 0;
}
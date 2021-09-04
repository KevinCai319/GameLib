#include "Handler.hpp"
int main() {
	Handler test;
	while (test.update() == 0);
	return 0;
}
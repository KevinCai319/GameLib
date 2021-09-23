#include "main.h"
#include "WindowHandler.hpp"
int main(){
	WindowHandler test(1920,1080,"test");
	while (test.update()==0)
	{
		test.render();
	}
	return 0;
}
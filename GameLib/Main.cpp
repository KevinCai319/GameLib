#include "DemoHandler.hpp"
#include "MainMenu.hpp"
#include <time.h> // header file for clock() function
#include <stdio.h> // header file for printf()
int main() {
	// clock_t start_time;
	// declare elapsed time, in milliseconds and seconds
	/*
	float elapsed_time_milli, elapsed_time_sec;
	int i=0;
	*/

	// C++ start time
	// start_time = clock();
	DemoHandler* main = new DemoHandler(1920, 1080, "Pong", new MainMenu());

	// while (main->update() == 0  && i++<10000) {
	while (main->update() == 0) {
		main->render();
	}
	// elapsed_time_milli = float(clock() - start_time);
	delete main;
	
	std::cout << "Exited successfully!" << std::endl;
	// printf("Time to do 10,000 empty loops is %f milliseconds\n", elapsed_time_milli);
	return 0;
}
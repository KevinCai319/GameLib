#include "Timed.hpp"
#include "TimedLayer.hpp"

TimedLayer::TimedLayer()
{
	timer.restart();
}

int TimedLayer::main()
{
	timer.restart();
	int res = Layer::main();
	if (res) return res;
	std::set<Layer*> timed = Layer::getTag("Timed");
	for (Layer* t : timed) {
		Timed* timedGroup = (Timed*)t;
		res = timedGroup->main(time);
		if (res) return res;
	}
	time = timer.getElapsedTime();
	return 0;
}

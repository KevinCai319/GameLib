#include "Timed.hpp"
#include "TimedLayer.hpp"

TimedLayer::TimedLayer()
{
	timer.restart(); 
}

int TimedLayer::main()
{
	for (Layer* group : toUpdate)
	{
		if (group->tags.find("Timed") != group->tags.end())
		{
			Timed* timedGroup = (Timed*)group; 
			timedGroup->main(timer.getElapsedTime());
		}
		else
		{
			group->update(); 
		}
	}
	timer.restart(); 
}

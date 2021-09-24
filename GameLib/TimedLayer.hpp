#pragma once
#include <SFML/System.hpp>
#include "Layer.hpp"
class TimedLayer : public Layer
{
private: 
	sf::Clock timer; 

public: 
	TimedLayer(); 
	virtual int main() override; 
};


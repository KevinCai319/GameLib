#pragma once
#include "Layer.hpp"
class Timed : public Layer
{
public: 
	Timed(); 
	virtual int main(sf::Time dt) = 0; 
};


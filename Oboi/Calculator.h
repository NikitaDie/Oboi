#pragma once
#include <iostream>
#include <map>
#include "structures.h"

class Calculator
{
private:
	// std::vector<ActiveRoom> activeRooms;


public:
	Calculator();

	std::vector<ActiveRoom> activeRooms; // temp

	float calculate();
};


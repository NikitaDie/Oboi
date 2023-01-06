#pragma once
#include <iostream>
#include <map>
#include "structures.h"

class Calculator
{
private:
	std::vector<ActiveRoom> activeRooms;


public:
	Calculator();

	void pushRoom(Room& r);

	void pushWall(int id_room, int wall, Roll& roll);

	void calculate(std::vector<Roll>& rolls);
};


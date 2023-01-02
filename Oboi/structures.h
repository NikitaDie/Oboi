#pragma once
#include "Room.h"
#include "Roll.h"

struct ActiveWall
{
	int wall;
	Roll* roll {nullptr};
};

struct ActiveRoom
{
	Room* room;
	std::vector<ActiveWall> activeWalls;
	bool withCeiling {false};
	Roll* ceilingRoll {nullptr};
};

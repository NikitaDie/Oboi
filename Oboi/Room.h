#pragma once
#include <string>
#include <vector>
#include "Wall.h"

class Room
{
private:
	const int WALLS_COUNT = 4;

	std::string title;
	float sizeA;
	float sizeB;
	std::vector<Wall> walls;

public:
	Room(std::string title, float a, float b, float h);

	std::string getTitle();

	Wall& getWall(int id);

	void addUseless(int wallId, float w, float h);

};


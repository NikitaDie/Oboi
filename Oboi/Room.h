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
	/*std::vector<Wall> walls;*/

public:
	Room(std::string title, float a, float b, float h);

	std::vector<Wall> walls; // temp

	std::string getTitle();

	void addUseless(int wallId, float w, float h);

	float getUsefullWallArea();
	float getCeilingArea();
};


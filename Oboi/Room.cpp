#include "Room.h"

Room::Room(std::string title, float a, float b, float h) :
	title{ title },
	sizeA{ a },
	sizeB{ b }
{
	for (int i{}; i < Room::WALLS_COUNT; ++i)
	{
		float length = i % 2 == 0 ? a : b;

		walls.push_back(Wall{ length, h });
	}
}

std::string Room::getTitle()
{
	return title;
}

void Room::addUseless(int wallId, float w, float h)
{
	walls[wallId].addUseless(w, h);
}

float Room::getUsefullWallArea()
{
	float area{};

	for (Wall& wall : walls)
		area += wall.getUsefulArea();

	return area;
}

float Room::getCeilingArea()
{
	return sizeA * sizeB;
}

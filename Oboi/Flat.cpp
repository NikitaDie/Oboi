#include "Flat.h"

Flat::Flat()
{}

void Flat::addRoom(std::string title, float a, float b, float h)
{
	rooms.push_back(Room{title, a, b, h});
}

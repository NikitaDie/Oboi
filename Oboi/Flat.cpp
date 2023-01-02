#include "Flat.h"
#include <iostream>

Flat::Flat()
{}

void Flat::addRoom(std::string title, float a, float b, float h)
{
	rooms.push_back(Room{title, a, b, h});
}

void Flat::printRooms()
{
	for (int i{ 0 }; i < rooms.size(); ++i) {
		std::cout << "\t" << rooms[i].getTitle() << " - " << i << "\n";
	}
}

Room& Flat::getRoom(int id)
{
	return rooms[id];
}

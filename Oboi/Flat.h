#pragma once
#include <vector>
#include "Room.h"

class Flat
{
private:
	std::vector<Room> rooms;

public:
	Flat();

	void addRoom(std::string title, float a, float b, float h);

	void printRooms();

	Room& getRoom(int id);


};


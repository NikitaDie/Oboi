#pragma once
#include <string>
#include <iostream>
#include "Room.h"
#include "Flat.h"
#include "Calculator.h"
class Conversation
{

private:
	int temp_number{ 0 };
	float temp_a{ 0 };
	float temp_b{ 0 };

public:

	int checkValue(int value, int min_d, int max_d = 100);

	void addRoomTextSizes(Flat& flat, std::string name);

	void addRoomText(Flat& flat);

	void printRolls(std::vector<Roll>& rolls);

	void addUselessText(Flat& flat);

	void addPapersText(std::vector<Roll>& rolls);

	void chooseWand(Flat& flat, Calculator& calc, std::vector<Roll>& rolls);



};


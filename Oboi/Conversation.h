#pragma once
#include <string>
#include <iostream>
#include "Room.h"
#include "Flat.h"
#include "Calculator.h"
class Conversation
{

private:
	const static int MAX_ROLL_PRICE = 200000;
	const static int MAX_ROLL_SIZE = 200;
	const static int MIN_ROLL_SIZE = 0;
	int temp_number{ 0 };
	float temp_a{ 0 };
	float temp_b{ 0 };

public:

	int checkValue(int value, int min_d, int max_d = 100);

	void checkValue(float& value1, float& value2, int min_d1, int max_d1, int min_d2, int max_d2);

	float checkValue(float value, int min_d, int max_d = 100);

	void addRoomTextSizes(Flat& flat, std::string name);

	void addRoomText(Flat& flat);

	void printRolls(std::vector<Roll>& rolls);

	void addUselessText(Flat& flat);

	void addPapersText(std::vector<Roll>& rolls);

	void chooseWand(Flat& flat, Calculator& calc, std::vector<Roll>& rolls);



};


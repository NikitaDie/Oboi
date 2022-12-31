#pragma once
#include <string>

class Roll
{
private:
	std::string title;
	float price;
	float width;
	float len;

public:
	Roll(std::string t, float p, float w, float l);

	std::string getTitle();
	float getPrice();
	float getArea();
};
#pragma once
#include <vector>
#include "Useless.h"


class Wall
{
private:
	float width {};
	float height {};
	std::vector<Useless> uselessObjects;

public:
	Wall(float w, float h);

	float getWidth();

	float getHeight();

	float getUsefulArea();

	void addUseless(float w, float h);

};


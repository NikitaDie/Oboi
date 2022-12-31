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

	void addUseless(float w, float h);

	float getUsefulArea();
};


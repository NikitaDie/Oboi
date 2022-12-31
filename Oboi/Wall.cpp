#include "Wall.h"

Wall::Wall(float w, float h):
	width {w},
	height {h}
{}

void Wall::addUseless(float w, float h)
{
	uselessObjects.push_back(Useless{ w, h });
}

float Wall::getUsefulArea()
{
	float area = width * height;

	for (Useless& useless : uselessObjects)
		area -= useless.getArea();

	return area;
}

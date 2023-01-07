#include "Wall.h"

Wall::Wall(float w, float h):
	width {w},
	height {h}
{}

float Wall::getWidth()
{
	return this->width;
}

float Wall::getHeight()
{
	return this->height;
}

float Wall::getUsefulArea()
{
	float area = width * height;

	for (Useless& useless : uselessObjects)
		area -= useless.getArea();

	return area;
}

void Wall::addUseless(float w, float h)
{
	uselessObjects.push_back(Useless{ w, h });
}
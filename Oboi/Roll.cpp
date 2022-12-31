#include "Roll.h"

Roll::Roll(std::string t, float p, float w, float l):
	title {t},
	price {p},
	width {w},
	len {l}
{}

std::string Roll::getTitle()
{
	return title;
}

float Roll::getPrice()
{
	return price;
}

float Roll::getArea()
{
	return width * len;
}

#include "Useless.h"

Useless::Useless(float w, float h):
	width {w},
	height {h}
{}

float Useless::getArea()
{
	return width * height;
}

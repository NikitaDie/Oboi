#pragma once

class Useless
{
private:
	float width{ 1 };
	float height{ 1 };
	float l_indent{};
	float t_indent{};
	float r_indent{};
	float b_indent{};

public:
	Useless(float w, float h);

	float getArea();
};

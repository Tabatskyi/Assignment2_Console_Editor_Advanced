#include "Coursor.h"


Coursor::Coursor()
{
	x = 0;
	y = 0;
}

Coursor::~Coursor() = default;

void Coursor::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coursor::GetPosition(int &x, int &y)
{
	x = this->x;
	y = this->y;
}
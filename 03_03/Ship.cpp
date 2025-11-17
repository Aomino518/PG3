#include "Ship.h"

Ship::Ship() : Vehicle("船")
{
}

Ship::~Ship()
{
}

void Ship::Move()
{
	std::cout << name_ << "は海を航行" << std::endl;
}

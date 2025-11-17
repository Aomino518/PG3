#include "Car.h"

Car::Car() : Vehicle("車")
{
}

Car::~Car()
{
}

void Car::Move()
{
	std::cout << name_ << "は走行" << std::endl;
}

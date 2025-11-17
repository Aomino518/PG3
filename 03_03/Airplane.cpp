#include "Airplane.h"

Airplane::Airplane() : Vehicle("飛行機")
{
}

Airplane::~Airplane()
{
}

void Airplane::Move()
{
	std::cout << name_ << "は空を飛行" << std::endl;
}

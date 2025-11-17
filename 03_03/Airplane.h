#pragma once
#include "Vehicle.h"

class Airplane : public Vehicle
{
public:
	Airplane();
	~Airplane();
	void Move() override;
};


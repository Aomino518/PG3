#pragma once
#include "Vehicle.h"

class Ship : public Vehicle
{
public:
	Ship();
	~Ship();
	void Move() override;
};


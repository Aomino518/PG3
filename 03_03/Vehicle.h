#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

class Vehicle
{
public:
	Vehicle(const char* name);
	virtual ~Vehicle();
	virtual void Move();

protected:
	const char* name_;
};
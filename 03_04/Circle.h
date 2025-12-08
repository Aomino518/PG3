#pragma once
#include "IShape.h"

class Circle : public IShape
{
public:
	Circle(double radius);
	void Size() override;
	void Draw() override;

private:
	double radius_;
	float area_;
};
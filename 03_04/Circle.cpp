#include "Circle.h" 
#include <iostream>
#include <numbers>

Circle::Circle(double radius)
{
	radius_ = radius;
	area_ = 0.0f;
}

void Circle::Size()
{
	area_ = std::numbers::pi_v<float> * radius_ * radius_;
}

void Circle::Draw()
{
	std::cout << "円面積" << area_ << std::endl;
}

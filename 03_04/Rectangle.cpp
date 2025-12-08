#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(float width, float height)
{
	width_ = width;
	height_ = height;
	area_ = 0.0f;
}

void Rectangle::Size()
{
	area_ = height_ * width_;
}

void Rectangle::Draw()
{
	std::cout << "矩形面積" << area_ << std::endl;
}

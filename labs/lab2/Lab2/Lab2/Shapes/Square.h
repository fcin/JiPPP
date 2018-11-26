#pragma once
#include "Rectangle.h"
#include "Polygon.h"
#include "Rhombus.h"

class Square : public Rectangle, public Rhombus
{
public:
	Square(Point2D lbCorner, double size);
	double Area() const override;
};

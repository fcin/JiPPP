#include "Square.h"

Square::Square(Point2D lbCorner, double size) 
	: Rectangle(lbCorner, size, size), Rhombus(Point2D(lbCorner.X + (size / 2), lbCorner.Y - (size / 2)), size, size)
{
}

double Square::Area() const
{
	return this->GetWidth() * this->GetHeight();
}

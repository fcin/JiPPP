#include "Square.h"

Square::Square(Point2D lbCorner, double size) 
	: Rectangle(lbCorner, size, size), Rhombus(Point2D(lbCorner.X + size, lbCorner.Y + size), size, size)
{
}

double Square::Area() const
{
	return this->GetWidth() * this->GetHeight();
}

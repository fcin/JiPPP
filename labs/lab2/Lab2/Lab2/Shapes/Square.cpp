#include "Square.h"

namespace Labs
{
	Square::Square(Point2D lbCorner, double size)
		: Rectangle(lbCorner, size, size), Rhombus(Point2D(lbCorner.X + (size / 2), lbCorner.Y - (size / 2)), size, size)
	{
	}

	double Square::Area() const
	{
		return this->GetWidth() * this->GetHeight();
	}

	void Square::Display(sf::RenderWindow & window)
	{
		Rectangle::Display(window);
	}

}
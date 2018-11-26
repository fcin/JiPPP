#include "Triangle.h"

Triangle::Triangle(Point2D anchor, double width, double height) 
	: m_Anchor(anchor), m_Width(width), m_Height(height) { }

double Triangle::Area() const
{
	return 1.0 / 2.0 * m_Width * m_Height;
}

bool Triangle::HasGreaterArea(Polygon& polygon) const
{
	return this->Area() > polygon.Area();
}



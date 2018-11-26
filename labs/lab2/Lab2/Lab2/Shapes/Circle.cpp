#include "Circle.h"

Circle::Circle(Point2D center, double radius) 
	: m_Center(center), m_Radius(radius) { }

double Circle::Area() const
{
	return 3.14159 * m_Radius * m_Radius;
}

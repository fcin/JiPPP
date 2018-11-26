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

void Triangle::Display(sf::RenderWindow& window)
{
	sf::CircleShape triangle((float)m_Width, 3);
	triangle.setFillColor(sf::Color::Red);
	triangle.setPosition((float)m_Anchor.X, (float)m_Anchor.Y);
	window.draw(triangle);
}



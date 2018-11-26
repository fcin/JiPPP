#include "Triangle.h"

Triangle::Triangle(Point2D center, double width, double height) 
	: m_Center(center), m_Width(width), m_Height(height) { }

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
	Point2D top = Point2D(m_Center.X, m_Center.Y - (m_Height / 2));
	Point2D left = Point2D(m_Center.X - m_Width / 2, m_Center.Y + (m_Height / 2));
	Point2D right = Point2D(m_Center.X + m_Width / 2, m_Center.Y + (m_Height / 2));

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f((float)top.X, (float)top.Y));
	triangle.setPoint(1, sf::Vector2f((float)left.X, (float)left.Y));
	triangle.setPoint(2, sf::Vector2f((float)right.X, (float)right.Y));

	triangle.setFillColor(sf::Color::Red);
	window.draw(triangle);
}



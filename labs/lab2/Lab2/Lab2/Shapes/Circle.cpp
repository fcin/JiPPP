#include "Circle.h"

namespace Labs
{
	Circle::Circle(Point2D center, double radius)
		: m_Center(center), m_Radius(radius) { }

	double Circle::Area() const
	{
		return 3.14159 * m_Radius * m_Radius;
	}

	void Circle::Display(sf::RenderWindow & window)
	{
		sf::CircleShape circle;
		float x = (float)(m_Center.X - m_Radius / 2);
		float y = (float)(m_Center.Y - m_Radius / 2);
		circle.setPosition(sf::Vector2f(x, y));
		circle.setRadius((float)m_Radius / 2);
		circle.setFillColor(sf::Color::Red);
		window.draw(circle);
	}
}
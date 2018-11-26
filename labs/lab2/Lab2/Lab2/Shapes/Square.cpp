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
		float x = (float)(m_LbCorner.X - m_Width / 2.0);
		float y = (float)(m_LbCorner.Y - m_Height / 2.0);
		sf::RectangleShape rect;
		rect.setSize(sf::Vector2f((float)m_Width, (float)m_Height));
		rect.setPosition(sf::Vector2f(x, y));
		rect.setFillColor(sf::Color::Green);
		window.draw(rect);
	}

}
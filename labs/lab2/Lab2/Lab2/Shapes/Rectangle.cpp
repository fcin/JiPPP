#include "Rectangle.h"

Rectangle::Rectangle(Point2D lbCorner, Point2D rtCorner) 
	: m_LbCorner(lbCorner), m_RtCorner(rtCorner)
{
	m_Width = m_RtCorner.X - m_LbCorner.X;
	m_Height = m_RtCorner.Y - m_LbCorner.Y;
}

Rectangle::Rectangle(Point2D lbCorner, double width, double height) 
	: m_LbCorner(lbCorner), m_Width(width), m_Height(height)
{
	m_RtCorner = Point2D(m_LbCorner.X + m_Width, m_LbCorner.Y + m_Height);
}

double Rectangle::Area() const
{
	return m_Width * m_Height;
}

void Rectangle::Display(sf::RenderWindow & window)
{
	float x = (float)(m_LbCorner.X - m_Width / 2.0);
	float y = (float)(m_LbCorner.Y - m_Height / 2.0);
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f((float)m_Width, (float)m_Height));
	rect.setPosition(sf::Vector2f(x, y));
	rect.setFillColor(sf::Color::Green);
	window.draw(rect);
}

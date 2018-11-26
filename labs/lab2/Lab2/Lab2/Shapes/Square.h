#pragma once
#include "Rectangle.h"
#include "Polygon.h"
#include "Rhombus.h"
#include <SFML/Graphics.hpp>

namespace Labs
{
	class Square : public Rectangle, public Rhombus
	{
	public:
		Square(Point2D lbCorner, double size);
		double Area() const override;
		void Display(sf::RenderWindow &window);
	};

}
#pragma once
#include <SFML/Graphics.hpp>

class Polygon
{
public:
	virtual double Area() const = 0;
	virtual void Display(sf::RenderWindow& window) = 0;
};

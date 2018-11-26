#include <iostream>
#include "Shapes/Point2D.h"
#include "Shapes/Triangle.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Circle.h"
#include "Shapes/Square.h"
#include "Shapes/Rhombus.h"

int main()
{
	Triangle tri(Point2D(0, 0), 5, 4);
	Rectangle rect = Square(Point2D(0, 0), 5);
	Polygon* rh = new Rhombus(Point2D(0, 0), 5, 3);
	std::cout << rh->Area() << std::endl;
	delete rh;
	std::getchar();
	return 0;
}
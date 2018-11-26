#pragma once
#include "Point2D.h"
#include "Polygon.h"

class Circle : public Polygon
{
private:
	Point2D m_Center;
	double m_Radius;

public:
	Circle(Point2D center, double radius);
	inline double GetRadius() const { return m_Radius; };
	double Area() const override;
};

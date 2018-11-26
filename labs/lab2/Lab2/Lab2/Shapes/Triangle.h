#pragma once
#include "Point2D.h"
#include "Polygon.h"

class Triangle : public Polygon
{
private:
	Point2D m_Anchor;
	double m_Width;
	double m_Height;

public:
	Triangle(Point2D anchor, double width, double height);
	inline double GetWidth() const { return m_Width; };
	inline double GetHeight() const { return m_Height; };
	double Area() const override;
	bool HasGreaterArea(Polygon& rect) const;
};

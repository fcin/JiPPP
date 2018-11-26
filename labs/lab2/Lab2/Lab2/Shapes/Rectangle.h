#pragma once
#include "Point2D.h"
#include "Polygon.h"
#include <SFML/Graphics.hpp>

namespace Labs
{
	class Rectangle : public virtual Polygon
	{
	protected:
		Point2D m_LbCorner;
		Point2D m_RtCorner;
		double m_Width;
		double m_Height;

	public:
		Rectangle(Point2D lbCorner, Point2D rtCorner);
		Rectangle(Point2D lbCorner, double width, double height);
		inline double GetWidth() const { return m_Width; };
		inline double GetHeight() const { return m_Height; };
		double Area() const override;
	};

}
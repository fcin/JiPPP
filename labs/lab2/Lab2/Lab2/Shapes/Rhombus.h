#pragma once
#include "Point2D.h"
#include "Polygon.h"

namespace Labs
{
	class Rhombus : public virtual Polygon
	{
	private:
		Point2D m_Center;
		double m_Diagonal1;
		double m_Diagonal2;

	public:
		Rhombus(Point2D center, double diag1, double diag2);
	};

}
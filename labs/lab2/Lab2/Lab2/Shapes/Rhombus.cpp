#include "Rhombus.h"

Rhombus::Rhombus(Point2D center, double diag1, double diag2) 
	: m_Center(center), m_Diagonal1(diag1), m_Diagonal2(diag2) { }

double Rhombus::Area() const
{
	return m_Diagonal1 * m_Diagonal2 / 2.0;
}

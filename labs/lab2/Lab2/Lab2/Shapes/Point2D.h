#pragma once

struct Point2D
{
	double X;
	double Y;

	inline Point2D() : X(0), Y(0) { }
	inline Point2D(double x, double y) : X(x), Y(y) { }
};

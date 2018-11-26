#include <string>
#include <vector>
#include <algorithm>

struct Point2D
{
    double x;
    double y;

    Point2D() : x(0), y(0) { }
    Point2D(double x, double y) : x(x), y(y) { }
};

class Rectangle
{

private:
    Point2D leftBottomCorner;
    double width;
    double height;

public:
    Rectangle();
    Rectangle(Point2D lbCorner, double width, double height);
    static Rectangle Parse(std::string &input);
    Rectangle GetIntersection(Rectangle const &other) const;
	std::string ToString() const;

private:
    static std::vector<std::string> Split(std::string& input, char character);
};

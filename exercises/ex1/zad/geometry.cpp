#include "geometry.h"
#include <algorithm>

Rectangle::Rectangle(Point2D lbCorner, double width, double height) 
	: leftBottomCorner(lbCorner), width(width), height(height) { }

Rectangle::Rectangle() : leftBottomCorner(Point2D(0.0, 0.0)), width(0.0), height(0.0) { }

Rectangle Rectangle::Parse(std::string &input)
{
    std::vector<std::string> params = Rectangle::Split(input, ' ');

    double xCorner = std::stod(params[0]);
    double yCorner = std::stod(params[1]);
    double width =   std::stod(params[2]);
    double height =  std::stod(params[3]);

    return Rectangle(Point2D(xCorner, yCorner), width, height);
}

Rectangle Rectangle::GetIntersection(Rectangle const &other) const
{
	double currX = this->leftBottomCorner.x;
	double currY = this->leftBottomCorner.y;
	double otherX = other.leftBottomCorner.x;
	double otherY = other.leftBottomCorner.y;

	double x1 = std::max(currX, otherX);
	double x2 = std::min(currX + this->width, otherX + other.width);
	double y1 = std::max(currY, otherY);
	double y2 = std::min(currY + this->height, otherY + other.height);

	if(x2 >= x1 && y2 >= y1)
		return Rectangle(Point2D(x1, y1), x2 - x1, y2 - y1);

	return Rectangle();
}

std::string Rectangle::ToString() const
{
    return std::to_string(leftBottomCorner.x) + 
		   std::string(" ") + 
		   std::to_string(leftBottomCorner.y) +
		   std::string(" ") + 
		   std::to_string(width) +
		   std::string(" ") + 
		   std::to_string(height);
}

// Splits string by specified character and trims additional spaces
std::vector<std::string> Rectangle::Split(std::string& input, char character)
{
    size_t start = input.find_first_not_of(character);
	size_t end = input.find_last_not_of(character) + 1;
    std::vector<std::string> params;
    int prevSubstring = start;
    for(size_t index = start; index < end; index++)
    {
         if(input.at(index) == character || (index + 1) == end)
         {
             int substringStart = prevSubstring == start ? prevSubstring : prevSubstring + 1;
             std::string param = input.substr(substringStart, index - prevSubstring);
			 if(param.find_first_not_of(character) == std::string::npos)
				continue;

             prevSubstring = index;
             params.push_back(param);
         }
    }

    return params;
}

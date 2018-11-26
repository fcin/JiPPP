#include <iostream>
#include <string>
#include "geometry.h"

int main()
{
    std::string rect1Input;
    std::getline(std::cin, rect1Input);

    std::string rect2Input;
    std::getline(std::cin, rect2Input);
 
    Rectangle rect1 = Rectangle::Parse(rect1Input);
    Rectangle rect2 = Rectangle::Parse(rect2Input);
    Rectangle crossSection = rect2.GetIntersection(rect1);

    std::cout << crossSection.ToString() << std::endl;
	std::getchar();
}

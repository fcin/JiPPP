#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Renderer.h"
#include "Shapes/Square.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Rhombus.h"

using namespace Labs;

std::string GetFontPath();

int main()
{
	std::cout << "Rectangle size in memory: " << sizeof(Labs::Rectangle) << std::endl;
	std::cout << "Rhombus size in memory: " << sizeof(Rhombus) << std::endl;
	std::cout << "Square size in memory: " << sizeof(Square) << std::endl;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Lab2", sf::Style::Default, settings);

	std::string filePath = GetFontPath();
	sf::Font font;

	if (!font.loadFromFile(filePath.c_str()))
	{
		std::getchar();
		return 0;
	}

	Renderer renderer(font);

	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					renderer.OnRightMouseClick(event.mouseButton.x, event.mouseButton.y);
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					renderer.OnLeftMouseClick(event.mouseButton.x, event.mouseButton.y);
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		renderer.DisplayAll(window);
	}

	std::getchar();
	return 0;
}

std::string GetFontPath()
{
	TCHAR szFileName[MAX_PATH + 1];
	GetModuleFileName(NULL, szFileName, MAX_PATH + 1);
	std::wstring fullPath(&szFileName[0]);
	std::string pathWithExtension(fullPath.begin(), fullPath.end());
	int extensionStart = pathWithExtension.find_last_of("\\");
	return pathWithExtension.substr(0, extensionStart) + std::string("\\ariblk.ttf");
}
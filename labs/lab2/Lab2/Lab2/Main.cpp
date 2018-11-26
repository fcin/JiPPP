#include <iostream>
#include <SFML/Graphics.hpp>
#include "Shapes/Point2D.h"
#include "Shapes/Triangle.h"
#include "Renderer.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Lab2", sf::Style::Default, settings);

	Renderer renderer;

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
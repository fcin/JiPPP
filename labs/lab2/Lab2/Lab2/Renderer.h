#pragma once
#include <vector>
#include "Shapes/Polygon.h"

namespace Labs
{
	class Renderer
	{
	private:
		std::vector<Polygon*> m_Shapes;
		sf::Font &m_Font;

	public:
		Renderer(sf::Font &font);
		~Renderer();
		void AddPolygon(Polygon *tri);
		void DisplayAll(sf::RenderWindow& window) const;
		void OnLeftMouseClick(int mouseX, int mouseY);
		void OnRightMouseClick(int mouseX, int mouseY);
	};

}
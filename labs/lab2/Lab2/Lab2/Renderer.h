#pragma once
#include <vector>
#include "Shapes/Polygon.h"
#include "Shapes/Triangle.h"

namespace Labs
{
	class Renderer
	{
	private:
		std::vector<Polygon*> m_Shapes;

	public:
		Renderer();
		~Renderer();
		void AddPolygon(Polygon *tri);
		void DisplayAll(sf::RenderWindow& window) const;
		void OnLeftMouseClick(int mouseX, int mouseY);
		void OnRightMouseClick(int mouseX, int mouseY);
	};

}
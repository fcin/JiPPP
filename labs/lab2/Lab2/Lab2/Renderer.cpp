#include "Renderer.h"
#include "Shapes/Square.h"
#include "Shapes/Circle.h"

namespace Labs
{
	Renderer::Renderer() { }

	Renderer::~Renderer()
	{
		for (size_t index = 0; index < m_Shapes.size(); index++)
			delete m_Shapes[index];

		m_Shapes.clear();
	}

	void Renderer::AddPolygon(Polygon *polygon)
	{
		m_Shapes.push_back(polygon);
	}

	void Renderer::DisplayAll(sf::RenderWindow& window) const
	{
		for (size_t index = 0; index < m_Shapes.size(); index++)
			m_Shapes[index]->Display(window);

		window.display();
	}

	void Renderer::OnLeftMouseClick(int mouseX, int mouseY)
	{
		Polygon* poly = new Square(Point2D(mouseX, mouseY), 100);
		AddPolygon(poly);
	}

	void Renderer::OnRightMouseClick(int mouseX, int mouseY)
	{
		Polygon* poly = new Circle(Point2D(mouseX, mouseY), 100);
		AddPolygon(poly);
	}

}
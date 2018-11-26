#include "Renderer.h"

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
	Polygon* tri = new Triangle(Point2D(mouseX, mouseY), 100, 100);
	AddPolygon(tri);
}

void Renderer::OnRightMouseClick(int mouseX, int mouseY)
{
	Polygon* tri = new Triangle(Point2D(mouseX, mouseY), 100, 100);
	AddPolygon(tri);
}

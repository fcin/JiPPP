#include "Renderer.h"
#include "Shapes/Square.h"
#include "Shapes/Circle.h"

namespace Labs
{
	Renderer::Renderer(sf::Font &font) : m_Font(font) { }

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
		double totalArea = 0;

		for (size_t index = 0; index < m_Shapes.size(); index++)
		{
			totalArea += m_Shapes[index]->Area();
			m_Shapes[index]->Display(window);
		}

		sf::Text totalAreaText;
		totalAreaText.setFont(m_Font);
		totalAreaText.setString(std::string("Total area: ") + std::to_string((int)totalArea));
		totalAreaText.setCharacterSize(18);
		totalAreaText.setFillColor(sf::Color::White);
		totalAreaText.setPosition(sf::Vector2f(50.0, (float)(window.getSize().y - 50)));

		window.draw(totalAreaText);

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
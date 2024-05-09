#include "CCanvas.h"

void CCanvas::Draw() const
{
	sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(800, 600), "Shapes"));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear(sf::Color::White);

		for (auto shape : m_shapes)
		{
			window.draw(*shape);
		}
		window.display();
	}
}

void CCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
	sf::VertexArray* line = new sf::VertexArray(sf::Lines, 2);

	(*line)[0] = sf::Vertex(sf::Vector2f((float)from.GetX(), (float)from.GetY()), sf::Color((lineColor << 8) | 0xFF));
	(*line)[1] = sf::Vertex(sf::Vector2f((float)to.GetX(), (float)to.GetY()), sf::Color((lineColor << 8) | 0xFF));

	m_shapes.push_back(line);
}

void CCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
	sf::ConvexShape* polygon = new sf::ConvexShape();

	polygon->setPointCount(points.size());

	for (size_t i = 0; i < points.size(); ++i)
	{
		polygon->setPoint(i, sf::Vector2f((float)points[i].GetX(), (float)points[i].GetY()));
	}

	polygon->setFillColor(sf::Color((fillColor << 8) | 0xFF));

	m_shapes.push_back(polygon);
}

void CCanvas::FillCircle(CPoint origin, double radius, uint32_t fillColor)
{
	sf::CircleShape* circle = new sf::CircleShape((float)radius);

	circle->setPosition(sf::Vector2f((float)(origin.GetX() - radius), (float)(origin.GetY() - radius)));
	circle->setFillColor(sf::Color((fillColor << 8) | 0xFF));

	m_shapes.push_back(circle);
}

void CCanvas::DrawCircle(CPoint origin, double radius, uint32_t lineColor)
{
	sf::CircleShape* circle = new sf::CircleShape((float)radius);

	circle->setPosition(sf::Vector2f((float)(origin.GetX() - radius), (float)(origin.GetY() - radius)));
	circle->setFillColor(sf::Color(0, 0, 0, 0));
	circle->setOutlineColor(sf::Color((lineColor << 8) | 0xFF));
	circle->setOutlineThickness(1.0f);

	m_shapes.push_back(circle);
}

void CCanvas::ClearShapes()
{
	for (auto shape : m_shapes)
	{
		delete shape;
	}

	m_shapes.clear();
}
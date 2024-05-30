#pragma once

#include "CPoint.h"
#include "ICanvas.h"
#include "ICanvasDrawable.h"
#include "SFML/Graphics.hpp"

class CCanvas : public ICanvas
{
public:
	CCanvas() = default;
	void Draw() const;
	void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
	void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
	void FillCircle(CPoint origin, double radius, uint32_t fillColor) override;
	void DrawCircle(CPoint origin, double radius, uint32_t lineColor) override;
private:
	std::vector<std::unique_ptr<sf::Drawable>> m_shapes;
};
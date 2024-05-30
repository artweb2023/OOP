#include "ShapeCreator.h"

void ShapeCreator::CreateLine(const CPoint start, const CPoint end, const uint32_t color = 0)
{
	m_shapes.push_back(std::make_unique<CLineSegment>(start, end, color));
}

void ShapeCreator::CreateRectangle(const CPoint leftTop, const CPoint rightBottom, const uint32_t outlineColor, const uint32_t fillColor)
{
	m_shapes.push_back(std::make_unique<CRectangle>(leftTop, rightBottom, outlineColor, fillColor));
}

void ShapeCreator::CreateTriangle(const CPoint p1, const CPoint p2, const CPoint p3, const uint32_t outlineColor, const uint32_t fillColor)
{
	m_shapes.push_back(std::make_unique<CTriangle>(p1, p2, p3, outlineColor, fillColor));
}

void ShapeCreator::CreateCircle(const CPoint origin, const double radius, const uint32_t outlineColor, const uint32_t fillColor)
{
	m_shapes.push_back(std::make_unique<CCircle>(origin, radius, outlineColor, fillColor));
}

const std::vector<std::unique_ptr<IShape>>& ShapeCreator::GetShapes() const
{
	return m_shapes;
}

void ShapeCreator::ClearShapes()
{
	m_shapes.clear();
}
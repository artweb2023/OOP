#pragma once

#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "IShape.h"
#include "stdafx.h"
#include "ÑTriangle.h"

class ShapeCreator
{
public:
	class ShapeCreator() {};
	void CreateLine(const CPoint start, const CPoint end, uint32_t color);
	void CreateRectangle(const CPoint leftTop, const CPoint rightBottom, const uint32_t outlineColor, const uint32_t fillColor);
	void CreateTriangle(const CPoint p1, const CPoint p2, const CPoint p3, const uint32_t outlineColor, const uint32_t fillColor);
	void CreateCircle(const CPoint origin, const double radius, const uint32_t outlineColor, const uint32_t fillColor);
	const std::vector<std::unique_ptr<IShape>>& GetShapes() const;
	void ClearShapes();

private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
};

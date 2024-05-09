#pragma once


#include "CPoint.h"
#include "stdafx.h"

class ICanvas
{
public:
	virtual ~ICanvas() {};
	// убрать этот метод
	/* virtual void Draw() const = 0; */
	virtual void DrawLine(CPoint from, CPoint to, uint32_t lineColor) = 0;
	virtual void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) = 0;
	virtual void FillCircle(CPoint origin, double radius, uint32_t fillColor) = 0;
	virtual void DrawCircle(CPoint origin, double radius, uint32_t lineColor) = 0;
	// убрать этот метод
	/*virtual void ClearShapes() = 0;*/
};
#pragma once
#include "CPoint.h"
#include "ICanvas.h"
#include "IShape.h"
#include "stdafx.h"
// вычисление длинны линии сделать отдельной функцией
class CLineSegment :public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t color = 0);
	double GetPerimeter() const override;
	double GetArea() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	uint32_t GetOutlineColor() const override;
	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;
private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
	std::string m_title;
};
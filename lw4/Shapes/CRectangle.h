#pragma once
#include "CPoint.h"
#include "ISolidShape.h"
#include "stdafx.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outlineColor = 0, uint32_t fillColor = 0);
	double GetPerimeter() const override;
	double GetArea() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	std::string ToString() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	void Draw(ICanvas& canvas) const;
private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
	std::string m_title;
};
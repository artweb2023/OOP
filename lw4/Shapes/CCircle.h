#pragma once

#include "CPoint.h"
#include "ICanvas.h"
#include "ISolidShape.h"
#include "stdafx.h"


class CCircle :public ISolidShape
{
public:
	CCircle(CPoint origin, double radius, uint32_t outlineColor = 0, uint32_t fillColor = 0);
	double GetPerimeter() const override;
	double GetArea() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	std::string ToString() const override;
	CPoint GetOrigin() const;
	double GetRadius() const;
	void Draw(ICanvas& canvas) const override;
private:
	CPoint m_origin;
	double m_radius;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
	std::string m_title;
};

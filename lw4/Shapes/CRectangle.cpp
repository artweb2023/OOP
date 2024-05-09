#include "CRectangle.h"


CRectangle::CRectangle(CPoint leftTop, CPoint rightBottom, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_title("Rectangle")
{
}

double CRectangle::GetPerimeter() const
{
	return (GetWidth() + GetHeight()) * 2;
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

// устранить дублирование кода то стринг
std::string CRectangle::ToString() const
{
	std::ostringstream oss;
	oss << m_title << ": "
		<< m_leftTop.ToString() << " "
		<< m_rightBottom.ToString() << " "
		<< "area " << std::fixed << std::setprecision(2) << GetArea() << " "
		<< "perimeter " << std::fixed << std::setprecision(2) << GetPerimeter() << " "
		<< "outline " << std::hex << GetOutlineColor()
		<< " fill " << std::hex << GetFillColor();
	return oss.str();
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	double x1 = m_rightBottom.GetX();
	double x2 = m_leftTop.GetX();
	return abs(x1 - x2);
}

double CRectangle::GetHeight() const
{
	double y1 = m_rightBottom.GetY();
	double y2 = m_leftTop.GetY();
	return abs(y1 - y2);
}

void CRectangle::Draw(ICanvas& canvas) const
{
	CPoint rightTop = CPoint(m_rightBottom.GetX(), m_leftTop.GetY());
	CPoint leftBottom = CPoint(m_leftTop.GetX(), m_rightBottom.GetY());

	std::vector<CPoint> vertexes = {
		m_leftTop,
		rightTop,
		m_rightBottom,
		leftBottom
	};

	canvas.FillPolygon(vertexes, m_fillColor);
	canvas.DrawLine(m_leftTop, rightTop, m_outlineColor);
	canvas.DrawLine(rightTop, m_rightBottom, m_outlineColor);
	canvas.DrawLine(m_rightBottom, leftBottom, m_outlineColor);
	canvas.DrawLine(leftBottom, m_leftTop, m_outlineColor);
}
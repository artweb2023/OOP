#include "ÑTriangle.h"


CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
	, m_title("Triangle")
{
}

double CTriangle::GetPerimeter() const
{
	CLineSegment line1(m_vertex1, m_vertex2);
	CLineSegment line2(m_vertex2, m_vertex3);
	CLineSegment line3(m_vertex3, m_vertex1);
	return line1.GetPerimeter() + line2.GetPerimeter() + line3.GetPerimeter();
}

double CTriangle::GetArea() const
{
	double a = CLineSegment(m_vertex1, m_vertex2).GetPerimeter();
	double b = CLineSegment(m_vertex2, m_vertex3).GetPerimeter();
	double c = CLineSegment(m_vertex3, m_vertex1).GetPerimeter();
	double s = (a + b + c) / 2;
	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CTriangle::ToString() const
{
	std::ostringstream oss;
	oss << m_title << ": "
		<< m_vertex1.ToString() << " "
		<< m_vertex2.ToString() << " "
		<< m_vertex3.ToString() << " "
		<< "area " << std::fixed << std::setprecision(2) << GetArea() << " "
		<< "perimeter " << std::fixed << std::setprecision(2) << GetPerimeter() << " "
		<< "outline " << std::hex << GetOutlineColor()
		<< " fill " << std::hex << GetFillColor();
	return oss.str();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> vertexes = {
		m_vertex1,
		m_vertex2,
		m_vertex3
	};

	canvas.FillPolygon(vertexes, m_fillColor);
	canvas.DrawLine(m_vertex1, m_vertex2, m_outlineColor);
	canvas.DrawLine(m_vertex2, m_vertex3, m_outlineColor);
	canvas.DrawLine(m_vertex3, m_vertex1, m_outlineColor);
}
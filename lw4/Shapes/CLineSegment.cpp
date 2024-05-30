#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t color)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(color)
	, m_title("Line")
{
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetLengthLine() const
{
	return sqrt(pow(m_startPoint.GetX() - m_endPoint.GetX(), 2) + pow(m_startPoint.GetY() - m_endPoint.GetY(), 2));
}

double CLineSegment::GetPerimeter() const
{
	return GetLengthLine();
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CLineSegment::ToString() const
{
	std::ostringstream oss;
	oss << m_title << ": "
		<< m_startPoint.ToString() << " "
		<< m_endPoint.ToString() << " "
		<< "area " << std::fixed << std::setprecision(2) << GetArea() << " "
		<< "perimeter " << std::fixed << std::setprecision(2) << GetPerimeter() << " "
		<< "length " << std::fixed << std::setprecision(2) << GetPerimeter() << " "
		<< "outline " << std::hex << GetOutlineColor();
	return oss.str();
}

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}
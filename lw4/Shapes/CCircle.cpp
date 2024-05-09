#include "CCircle.h"

CCircle::CCircle(CPoint origin, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_title("Circle")
	, m_origin(origin)
	, m_radius(abs(radius))
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

std::string CCircle::ToString() const
{
	std::ostringstream oss;
	oss << m_title << ": "
		<< m_origin.ToString() << " "
		<< "area " << std::fixed << std::setprecision(2) << GetArea() << " "
		<< "perimeter " << std::fixed << std::setprecision(2) << GetPerimeter() << " "
		<< "radius  " << std::fixed << std::setprecision(2) << GetRadius() << " "
		<< "outline " << std::hex << GetOutlineColor()
		<< "fill " << std::hex << GetFillColor();
	return oss.str();
}

CPoint CCircle::GetOrigin() const
{
	return m_origin;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.FillCircle(m_origin, m_radius, m_fillColor);
	canvas.DrawCircle(m_origin, m_radius, m_outlineColor);
}
